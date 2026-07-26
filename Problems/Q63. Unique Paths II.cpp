class Solution {
    int dp[101][101];

    int helper(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i >= m || j >= n) return 0;//out of bound

        
        if (grid[i][j] == 1) return 0;//obstacle

        if (i == m - 1 && j == n - 1) return 1;//Base Case

        //Return dpized answer if already calculated
        if (dp[i][j] != -1) return dp[i][j];

        // Down + Right recursive calls
        return dp[i][j] = helper(grid, i + 1, j, m, n) + helper(grid, i, j + 1, m, n);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // Initialize dp table with -1
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }
        
        return helper(obstacleGrid, 0, 0, m, n);
    }
};
