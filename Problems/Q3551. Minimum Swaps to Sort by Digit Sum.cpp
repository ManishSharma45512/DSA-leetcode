class Solution {
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // Element structure: {digit_sum, original_value, original_index}
        struct Element {
            int digit_sum;
            int val;
            int orig_idx;
        };

        vector<Element> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {getDigitSum(nums[i]), nums[i], i};
        }

        // Sort based on digit sum, then value
        sort(arr.begin(), arr.end(), [](const Element& a, const Element& b) {
            if (a.digit_sum != b.digit_sum) {
                return a.digit_sum < b.digit_sum;
            }
            return a.val < b.val;
        });

        // Visited array to detect cycles
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            // Already visited or already at its correct target position
            if (visited[i] || arr[i].orig_idx == i) {
                continue;
            }

            int cycle_length = 0;
            int curr = i;

            while (!visited[curr]) {
                visited[curr] = true;
                curr = arr[curr].orig_idx;
                cycle_length++;
            }

            if (cycle_length > 1) {
                swaps += (cycle_length - 1);
            }
        }

        return swaps;
    }
};
