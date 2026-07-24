class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxVal = 0;
        for (int num : nums) {
            maxVal = max(maxVal, num);
        }

        vector<int> points(maxVal + 1, 0);
        for (int num : nums) {//calculating total points available for number
            points[num] += num;
        }

        int prev2 = 0;
        int prev1 = 0;

        for (int i = 0; i <= maxVal; i++) {// |nums[i]-1 && nums[i]+1|=2 so we do house robbery alternatively
            int current = max(prev1, prev2 + points[i]);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};
