class Solution {
    int helper(vector<int>& nums, int i, vector<int>& dp) {
        if (dp[i] != -1) return dp[i];// Return already computed result

        int maxl = 0;

        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] > nums[i]) {
                int curr = helper(nums, j, dp);
                if (curr > maxl) {
                    maxl = curr;
                }
            }
        }

        return dp[i] = 1 + maxl;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, -1);
        int maxl = 0;

        for (int i = 0; i < n; i++) {
            int curr = helper(nums, i, dp);
            if (curr > maxl) {
                maxl = curr;
            }
        }

        return maxl;
    }
};
