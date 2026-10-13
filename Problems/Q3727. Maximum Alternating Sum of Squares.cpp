class Solution {
public:
    void countingSort(vector<int>& nums) {
        if (nums.empty()) return;

        // Map everything to absolute values since score only depends on squares
        int max_val = 0;
        for (int x : nums) {
            max_val = max(max_val, abs(x));
        }

        // Count occurrences of each magnitude
        vector<int> count(max_val + 1, 0);
        for (int x : nums) {
            count[abs(x)]++;
        }

        // Reconstruct sorted by magnitude (smallest to largest)
        int idx = 0;
        for (int i = 0; i <= max_val; i++) {
            while (count[i] > 0) {
                nums[idx++] = i;
                count[i]--;
            }
        }
    }

    long long maxAlternatingSum(vector<int>& nums) {
        countingSort(nums);
        
        int n = nums.size();
        vector<int> temp = nums;
        long long ans = 0;

        // Smallest n/2 elements are subtracted
        int num_subtract = n / 2;
        for (int i = 0; i < num_subtract; i++) {
            long long val = temp[i];
            ans -= val * val;
        }

        // Largest remaining elements are added
        for (int i = num_subtract; i < n; i++) {
            long long val = temp[i];
            ans += val * val;
        }

        return ans;
    }
};
