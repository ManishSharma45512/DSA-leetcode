//I took Gemini help to improve code a from I to II because i am still learning ;)


class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return 0;

        long long total_count = 0;
        int prefix_sum = 0;

        // Since prefix_sum can range from -n to +n, total range size is 2*n + 1
        // We use an offset of 'n' to handle negative indices safely.
        vector<int> count_map(2 * n + 1, 0);
        
        // Base case: Before starting, prefix_sum is 0. 
        // Its frequency at index (0 + n) is initialized to 1.
        count_map[0 + n] = 1;

        // This tracks the running total of valid prefix sums seen so far
        long long valid_previous_sums = 0;

        for (int i = 0; i < n; i++) {
            // Step 1: Update prefix sum based on target matching
            if (nums[i] == target) {
                prefix_sum++;
                // Moving right (+1) means the previous prefix_sum value 
                // now becomes strictly smaller than the current one.
                valid_previous_sums += count_map[prefix_sum - 1 + n];
            } else {
                prefix_sum--;
                // Moving left (-1) means the current prefix_sum value
                // drops below what was previously the boundary.
                valid_previous_sums -= count_map[prefix_sum + n];
            }

            // Step 2: Add the count of valid historical points ending at this index
            total_count += valid_previous_sums;

            // Step 3: Log the current prefix sum into our frequency tracker
            count_map[prefix_sum + n]++;
        }

        return total_count;
    }
};
