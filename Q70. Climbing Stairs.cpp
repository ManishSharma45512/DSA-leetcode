class Solution {
public:
    int climbStairs(int n) {
        // Base cases
        if (n <= 1) return 1;
        
        
        vector<int> dp(n + 1, 0);
        
        // Starting points
        dp[1] = 1; // 1 way to reach the 1st step (1)
        dp[2] = 2; // 2 ways to reach the 2nd step (1+1, or 2)
        
        // Build up the answers from step 3 to n
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
};
