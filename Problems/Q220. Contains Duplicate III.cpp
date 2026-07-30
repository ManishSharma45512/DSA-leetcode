class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> window;

        for (int i = 0; i < nums.size(); i++) {
            // Maintain sliding window size <= indexDiff
            if (i > indexDiff) {
                window.erase(nums[i - indexDiff - 1]);
            }

            // Find first element >= (nums[i] - valueDiff)
            auto it = window.lower_bound((long long)nums[i] - valueDiff);

            // Check if element exists and is <= (nums[i] + valueDiff)
            if (it != window.end() && *it <= (long long)nums[i] + valueDiff) {
                return true;
            }

            window.insert(nums[i]);
        }

        return false;
    }
};
