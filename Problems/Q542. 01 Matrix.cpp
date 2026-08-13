class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int INF = m + n; // A value larger than any max possible distance

        vector<vector<int>> dp(m, vector<int>(n, INF));

        //Top-Left to Bottom-Right (check Top and Left neighbors)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1); // Top
                    if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1); // Left
                }
            }
        }

        //Bottom-Right to Top-Left (check Bottom and Right neighbors)
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i < m - 1) dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1); // Bottom
                if (j < n - 1) dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1); // Right
            }
        }

        return dp;
    }
};
