class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        vector<int> res;

        for (const auto& p : freq) {
            if (p.second == 1) {
                res.push_back(p.first);
            }
        }

        return res;
    }
};
