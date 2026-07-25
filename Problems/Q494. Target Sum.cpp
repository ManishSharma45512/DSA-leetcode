class Solution {
    int count = 0;

private:
    void helper(vector<int>& nums, int target, int idx, int currentSum) {
        
        if (idx == nums.size()) {// Base Case
            if (currentSum == target) {
                count++;
            }
            return;
        }

        //add positive
        helper(nums, target, idx + 1, currentSum + nums[idx]);

        //add negative
        helper(nums, target, idx + 1, currentSum - nums[idx]);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        count = 0; //Reset
        helper(nums, target, 0, 0);
        return count;
    }
};
