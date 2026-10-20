class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        
        // Find all divisors of n
        vector<int> divisors;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i * i != n) {
                    divisors.push_back(n / i);
                }
            }
        }

        int total_sum = 0;

        for (int k : divisors) {
            bool valid = true;
            int prev_max = -1;

            for (int start = 0; start < n; start += k) {
                int drop_count = 0;
                int drop_idx = -1;

                // Check circular drops in current block
                for (int i = 0; i < k; i++) {
                    int curr = nums[start + i];
                    int next = nums[start + (i + 1) % k];
                    if (curr > next) {
                        drop_count++;
                        drop_idx = i;
                    }
                }

                if (drop_count > 1) {
                    valid = false;
                    break;
                }

                int block_min, block_max;
                if (drop_count == 0) {
                    // All elements in block are equal
                    block_min = nums[start];
                    block_max = nums[start];
                } else {
                    // Exactly one drop
                    block_max = nums[start + drop_idx];
                    block_min = nums[start + (drop_idx + 1) % k];
                }

                // Check inter-block ordering
                if (prev_max != -1 && prev_max > block_min) {
                    valid = false;
                    break;
                }

                prev_max = block_max;
            }

            if (valid) {
                total_sum += k;
            }
        }

        return total_sum;
    }
};
