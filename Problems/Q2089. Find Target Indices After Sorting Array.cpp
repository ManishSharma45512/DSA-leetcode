class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less_than = 0;
        int target_count = 0;

        for (int x : nums) {
            if (x < target) {
                less_than++;
            } else if (x == target) {
                target_count++;
            }
        }

        vector<int> result;
        result.reserve(target_count);

        for (int i = 0; i < target_count; i++) {
            result.push_back(less_than + i);
        }

        return result;
    }
};
