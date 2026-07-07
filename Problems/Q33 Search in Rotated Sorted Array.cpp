

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int start, int end) {
        if (start > end) return -1; // Base case

        int mid = start + (end - start) / 2; 

        if (nums[mid] == target) return mid;

        
        if (nums[start] <= nums[mid]) {
            
            if (target >= nums[start] && target < nums[mid]) {
                return binarySearch(nums, target, start, mid - 1);
            }
            
            return binarySearch(nums, target, mid + 1, end);
        } 
        
        else {
            
            if (target > nums[mid] && target <= nums[end]) {
                return binarySearch(nums, target, mid + 1, end);
            }
            
            return binarySearch(nums, target, start, mid - 1);
        }
    }

    
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};
