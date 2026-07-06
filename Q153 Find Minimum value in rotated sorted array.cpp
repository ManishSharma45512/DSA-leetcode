class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;

        if (nums[st] <= nums[end]) {
            return nums[st];
        }

       
        while (st < end) {
            int mid = st + (end - st) / 2;

            
            if (nums[mid] > nums[end]) {
                st = mid + 1;
            } 
            // Otherwise, the minimum value is in the left half (including mid)
            else {
                end = mid;
            }
        }

        // When st == end, it will point directly to the minimum element
        return nums[st];
    }
};
