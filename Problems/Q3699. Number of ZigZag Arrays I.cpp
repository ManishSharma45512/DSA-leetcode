class Solution {
public:
    const long long MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1; // shifting of range

        // If pool is 1 element and n > 1, no zigzag array can be formed
        if (m == 1 && n > 1) return 0;
        if (n == 1) return m;

        vector<vector<int>> up(n + 1, vector<int>(m + 1, 0));   // UP DP
        vector<vector<int>> down(n + 1, vector<int>(m + 1, 0)); // DOWN DP

        for(int x = 0; x < m; x++) {
            for(int y = 0; y < m; y++) {
                if(x == y) continue;
                
                if(x < y) {
                    up[2][y] = (up[2][y] + 1) % MOD;
                } else {
                    down[2][y] = (down[2][y] + 1) % MOD;
                }
            }
        }

        for(int i = 3; i <= n; i++) {
            vector<int> prefUp(m + 1, 0), prefDown(m + 1, 0);
            for(int v = 0; v < m; v++) {
                prefUp[v + 1] = (prefUp[v] + up[i - 1][v]) % MOD;
                prefDown[v + 1] = (prefDown[v] + down[i - 1][v]) % MOD;
            }

            // Fixed: Added space to 'int y'
            for(int y = 0; y < m; y++) {
                // up[i][y] = sum of down[i-1][x] for x < y
                up[i][y] = prefDown[y];  

                // Fixed: Changed prefDown[y+1] to prefUp[y+1]
                down[i][y] = (prefUp[m] - prefUp[y + 1] + MOD) % MOD; 
            }
        }

        long long ans = 0;
        for(int y = 0; y < m; y++) {
            ans = (ans + up[n][y] + down[n][y]) % MOD;
        }

        return ans;   
    }
};
