

//define ll long long int
//define mod 1000000007

class Solution {
    // Definining types and constants within the class scope
    typedef long long ll;
    const ll mod = 1e9 + 7;

public:
    vector<vector<ll>> multiply(vector<vector<ll>>& A, vector<vector<ll>>& B) {
        int n = A.size();
        vector<vector<ll>> C(n, vector<ll>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;
                    
                    // Simplified modulo expression for efficiency
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
                }
            }
        }
        return C;
    }

    vector<vector<ll>> power(vector<vector<ll>> base, long long exp) {
        int n = base.size();
        vector<vector<ll>> result(n, vector<ll>(n, 0));

        for (int i = 0; i < n; i++) {
            result[i][i] = 1;
        }

        while (exp > 0) {
            if (exp & 1) {
                result = multiply(result, base);
            }
            base = multiply(base, base);
            exp >>= 1;
        }
        return result;
    }
    
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        
        // Base edge cases handling
        if (m == 1 && n > 1) return 0;
        if (n == 1) return m;

        int S = 2 * m;

        auto U = [&](int v) {
            return v - 1;
        };

        auto D = [&](int v) {
            return m + (v - 1);
        };

        vector<vector<ll>> T(S, vector<ll>(S, 0));

        for (int v = 1; v <= m; v++) {
            for (int u = 1; u < v; u++) {
                T[U(v)][D(u)] = 1;
            }
            for (int u = v + 1; u <= m; u++) {
                T[D(v)][U(u)] = 1;
            }
        }

        vector<ll> dp2(S, 0);
        for (int v = 1; v <= m; v++) {
            dp2[U(v)] = v - 1;
            dp2[D(v)] = m - v;
        }

        // Exponent is safe now because n >= 2
        vector<vector<ll>> P = power(T, n - 2);

        vector<long long> dpn(S, 0);
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {
                dpn[i] = (dpn[i] + P[i][j] * dp2[j]) % mod;
            }
        }

        long long ans = 0;
        for (long long x : dpn) {
            ans = (ans + x) % mod;
        }

        return ans;
    }
};
