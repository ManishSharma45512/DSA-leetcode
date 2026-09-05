class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        // suffix_min[i] = min(nums[i..n-1])
        vector<int> suffix_min(n);
        suffix_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix_min[i] = min(nums[i], suffix_min[i + 1]);
        }

        // Maintain prefix_max on the fly
        int prefix_max = nums[0];
        for (int i = 0; i < n; i++) {
            prefix_max = max(prefix_max, nums[i]);
            
            // Instability score: max(nums[0..i]) - min(nums[i..n-1])
            // Using long long to prevent potential overflow if subtraction involves large types
            if ((long long)prefix_max - suffix_min[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};
