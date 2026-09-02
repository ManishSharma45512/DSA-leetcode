class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        // dp[i][j] will store the minimum arm length from all 4 directions
        vector<vector<int>> dp(n, vector<int>(n, n));

        // Mark mines directly in dp as 0
        for (const auto& mine : mines) {
            dp[mine[0]][mine[1]] = 0;
        }

        // Compute Left, Right, Up, Down arm lengths
        for (int i = 0; i < n; i++) {
            int left = 0, right = 0, up = 0, down = 0;

            for (int j = 0, k = n - 1; j < n; j++, k--) {
                // Left to Right: row i, col j
                left = (dp[i][j] == 0) ? 0 : left + 1;
                dp[i][j] = min(dp[i][j], left);

                // Right to Left: row i, col k
                right = (dp[i][k] == 0) ? 0 : right + 1;
                dp[i][k] = min(dp[i][k], right);

                // Top to Bottom: row j, col i
                up = (dp[j][i] == 0) ? 0 : up + 1;
                dp[j][i] = min(dp[j][i], up);

                // Bottom to Top: row k, col i
                down = (dp[k][i] == 0) ? 0 : down + 1;
                dp[k][i] = min(dp[k][i], down);
            }
        }

        // Find the maximum plus sign order across all cells
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};
