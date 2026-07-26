class Solution {
    int dp[101][101];

    int helper(int i, int j, int m, int n) {

        if (i >= m || j >= n) return 0;//out of bound

        if (i == m - 1 && j == n - 1) return 1;//Base Case

        if (dp[i][j] != -1) return dp[i][j];//already visited

        
        return dp[i][j] = helper(i + 1, j, m, n) + helper(i, j + 1, m, n);// Down + Right recursive calls
    }

public:
    int uniquePaths(int m, int n) {
        // Initialize dp table with -1
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }

        return helper(0, 0, m, n);
    }
};
