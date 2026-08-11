class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefixSum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                prefixSum += nums[i];
            } else {
                break; // Sequential chain broke!
            }
        }

        unordered_set<int> numSet(nums.begin(), nums.end());


        int x = prefixSum;
        while (numSet.count(x)) {
            x++;
        }

        return x;
    }
};
