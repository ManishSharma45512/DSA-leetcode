class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> count;

        for (int num : nums) {
            count[num]++;
        }


        for (int i = 0; i <= n; i++) {
            if (count[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};
