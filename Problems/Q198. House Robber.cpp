class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n, 0);

        // Base cases 
        dp[0] = nums[0];                   // If 1 house, rob it.
        dp[1] = max(nums[0], nums[1]);     // If 2 houses, rob the one with more money.

         
        for(int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }

        // Last element have most money
        return dp[n-1];
    }
};
