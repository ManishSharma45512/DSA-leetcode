class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<long long> maxi(3, LLONG_MIN);

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == maxi[0] ||
                nums[i] == maxi[1] ||
                nums[i] == maxi[2]) {
                continue;
            }

            if (nums[i] > maxi[0]) {
                maxi[2] = maxi[1];
                maxi[1] = maxi[0];
                maxi[0] = nums[i];
            }
            else if (nums[i] > maxi[1]) {
                maxi[2] = maxi[1];
                maxi[1] = nums[i];
            }
            else if (nums[i] > maxi[2]) {
                maxi[2] = nums[i];
            }
        }

        return maxi[2] == LLONG_MIN ? maxi[0] : maxi[2];
    }
};
