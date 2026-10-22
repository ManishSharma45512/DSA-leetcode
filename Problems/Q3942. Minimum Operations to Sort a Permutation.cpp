class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = ranges::find(nums, 0) - nums.begin();
        
        // Lambda to check if the elements form a valid sorted order with a given step direction
        auto check = [&](int step) -> bool {
            for (int i = 1; i < n; i++) {
                int prev = (zero + (i - 1) * step + n) % n;
                int curr = (zero + i * step + n) % n;
                if (nums[prev] > nums[curr]) {
                    return false;
                }
            }
            return true;
        };

        int ans = INT_MAX;

        // Case 1: Increasing sequence (step = 1)
        if (check(1)) {
            ans = min(ans, zero);            // Rotate left 'zero' times
            ans = min(ans, n - zero + 2);    // Reverse, rotate, reverse back
        }

        // Case 2: Decreasing sequence (step = -1)
        if (check(-1)) {
            ans = min(ans, zero + 2);        // Rotate, then reverse (or reverse, then rotate)
            ans = min(ans, n - zero);        
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
