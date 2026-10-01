class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        //find pivot
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // If no pivot exists, the array is in descending order
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        //finding next larger number
        for (int i = n - 1; i > pivot; --i) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        //reverse from pivot+1->n-1
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};
