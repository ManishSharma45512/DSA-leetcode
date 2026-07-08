class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int MOD = 1000000007;

        // Precompute powers of 10 to help us shift digit places in O(1)
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        // Prefix arrays for O(1) range lookups
        vector<int> sumD(n + 1, 0);   // Accumulates digit sums
        vector<int> cntN0(n + 1, 0);  // Accumulates count of non-zero digits
        vector<long long> p(n + 1, 0); // Accumulates concatenated integer value modulo MOD

        for (int i = 1; i <= n; i++) {
            int d = s[i - 1] - '0';
            sumD[i] = sumD[i - 1] + d;
            cntN0[i] = cntN0[i - 1] + (d > 0 ? 1 : 0);
            
            // If the digit isn't zero, shift the previous concatenation left and append d
            p[i] = (d > 0) ? (p[i - 1] * 10 + d) % MOD : p[i - 1];
        }

        vector<int> result;

        // Process each query in absolute O(1) time!
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            //Get the non-zero digit count and digit sum in the range [l, r]
            int n0 = cntN0[r + 1] - cntN0[l];
            int sd = sumD[r + 1] - sumD[l];

            //Mathematically strip out the prefix number prior to our left boundary 'l'
            long long x = (p[r + 1] - (p[l] * pow10[n0]) % MOD + MOD) % MOD;

            //Compute final answer for this range
            long long ans = (x * sd) % MOD;
            result.push_back((int)ans);
        }

        return result;
    }
};
