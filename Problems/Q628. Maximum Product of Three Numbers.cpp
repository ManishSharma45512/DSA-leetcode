class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        //Two smallest (most negative) numbers * largest number
        int option1 = nums[0] * nums[1] * nums[n - 1];

        //Three largest numbers
        int option2 = nums[n - 1] * nums[n - 2] * nums[n - 3];

        //return max value
        return max(option1, option2);
    }
};
