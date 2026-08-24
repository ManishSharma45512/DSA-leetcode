class Solution {
    int longestincreasing(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int prev) {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] <= prev) {// Base case: out of bounds or not strictly greater than previous cell
            return 0;
        }

        if (dp[i][j] != 0) {//already computed
            return dp[i][j];
        }

        int currVal = matrix[i][j];

        int left  = longestincreasing(matrix, dp, i, j - 1, currVal);
        int up    = longestincreasing(matrix, dp, i - 1, j, currVal);
        int right = longestincreasing(matrix, dp, i, j + 1, currVal);
        int down  = longestincreasing(matrix, dp, i + 1, j, currVal);

        //Max path length from this cell is 1 (itself) + max of valid neighbors
        return dp[i][j] = 1 + max({left, up, right, down});
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int maxi = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int len = longestincreasing(matrix, dp, i, j, -1);
                maxi = max(maxi, len);
            }
        }

        return maxi;
    }
};
