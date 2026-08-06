class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // mid ^ 1 converts an even mid to mid + 1, and an odd mid to mid - 1
            if (nums[mid] == nums[mid ^ 1]) {
                // Partner matches expected pair indexing -> single element is to the right
                left = mid + 1;
            } else {
                // Pattern broken -> single element is at mid or to the left
                right = mid;
            }
        }

        return nums[left];
    }
};
