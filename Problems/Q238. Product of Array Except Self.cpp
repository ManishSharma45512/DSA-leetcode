class Solution {
    int productExceptI(vector<int>& nums, int i) {
        int p = 1;
        for (int j = 0; j < nums.size(); j++) {
            if (j == i) continue;
            p *= nums[j];
        }
        return p;
    }

public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount = 0;
        int totalProductWithoutZero = 1;

        for (int num : nums) {
            if (num == 0) {
                zeroCount++;
            } else {
                totalProductWithoutZero *= num;
            }
        }

        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            if (zeroCount > 1) {
                
                res.push_back(0);
            } else if (zeroCount == 1) {
                if (nums[i] == 0) {
                    res.push_back(totalProductWithoutZero);
                } else {
                    res.push_back(0);
                }
            } else {
                res.push_back(totalProductWithoutZero / nums[i]); 
            }
        }

        return res;
    }
};
