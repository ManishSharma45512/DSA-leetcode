class Solution {
public:
    int sumOfSquares(std::vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                int val = nums[i - 1];// 1-based index i corresponds to nums[i - 1]
                sum += val * val;
            }
        }

        return sum;
    }
};
