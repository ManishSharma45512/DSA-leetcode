class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        long long cost = 0;
        // Store indices of `nums` with `nums[i]` in non-increasing order.
        deque<int> dq;
        
        for (int i = nums.size() - 1, j = nums.size() - 1; i >= 0; --i) {
            const int num = nums[i];
            
            // Maintain monotonic deque (non-increasing order)
            while (!dq.empty() && nums[dq.back()] < num) {
                const int l = dq.back();
                dq.pop_back();
                const int r = dq.empty() ? j + 1 : dq.back();
                // Adjust `nums[l]` to `num`
                cost += static_cast<long long>(r - l) * (num - nums[l]);
            }
            dq.push_back(i);
            
            // Shrink the window from the right if cost exceeds k
            while (cost > k) {
                cost -= nums[dq.front()] - nums[j];
                if (dq.front() == j) {
                    dq.pop_front();
                }
                --j;
            }
            
            // All subarrays starting at `i` and ending between `i` and `j` are valid
            ans += j - i + 1;
        }
        
        return ans;
    }
};
