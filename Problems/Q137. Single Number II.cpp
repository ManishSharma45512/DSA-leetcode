class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        for (const auto& [val, count] : freq) {
            if (count == 1) return val;
        }

        return -1;
    }
};
