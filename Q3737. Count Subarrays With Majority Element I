class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int total_count = 0;
        
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq; 
            
            for (int j = i; j < n; j++) {
                freq[nums[j]]++; // Increment the frequency of the current element
                
                int subarray_length = j - i + 1;
                
                // Target is the majority element if its count is strictly > half the length

                //Being half of total lenbth is not majority
                if (freq[target] > subarray_length / 2) {
                    total_count++;
                }
            }
        }
        
        return total_count;
    }
};
