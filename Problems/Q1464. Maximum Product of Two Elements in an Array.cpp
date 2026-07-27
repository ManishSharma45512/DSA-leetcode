class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());//O(nlogn)

        int n = nums.size();

        int val1 = nums[n - 1]-1;
        int val2 = nums[n - 2]-1;

        return val1 * val2; 
    }
};
