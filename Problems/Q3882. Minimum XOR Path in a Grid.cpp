class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // dp[i][j] is a bitset where the k-th bit is true if XOR sum 'k' is reachable at (i, j)
        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));

        // Base case: start at (0, 0), including grid[0][0]
        dp[0][0].set(grid[0][0]);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                
                for (int val = 0; val < 1024; ++val) {
                    if (!dp[i][j].test(val)) continue;

                    // Move downwards
                    if (i + 1 < m) {
                        int next_val = val ^ grid[i + 1][j];
                        dp[i + 1][j].set(next_val);
                    }

                    // Move rightwards
                    if (j + 1 < n) {
                        int next_val = val ^ grid[i][j + 1];
                        dp[i][j + 1].set(next_val);
                    }
                }
            }
        }

        for (int val = 0; val < 1024; ++val) {
            if (dp[m - 1][n - 1].test(val)) {
                return val;
            }
        }

        return 0;
    }
};
