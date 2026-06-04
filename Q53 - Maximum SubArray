class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
       
        int subArray = nums[0]; 

        //  we are looking at every possible starting position 'i'
        for (int i = 0; i < n; i++) {
            int current_sum = 0;
            
            // extend to the right and update the maximum on the fly
            for (int j = i; j < n; j++) {
                current_sum += nums[j];
                subArray = max(subArray, current_sum);
            }
        }
        
        return subArray;
    }
};
