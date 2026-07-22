class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) return 0;

        sort(nums.begin(), nums.end());

        // Base case: move all elements in the same direction (+k or -k)
        int minRange = nums[n - 1] - nums[0];

        //Try every split
        for (int i = 0; i < n - 1; i++) {
            int currentMax = max(nums[i] + k, nums[n - 1] - k);
            int currentMin = min(nums[0] + k, nums[i + 1] - k);

            minRange = min(minRange, currentMax - currentMin);
        }

        return minRange;
    }
};
