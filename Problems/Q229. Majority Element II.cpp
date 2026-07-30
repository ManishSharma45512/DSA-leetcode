class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int require = n / 3;
        unordered_map<int, int> freq; // number -> frequency

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        vector<int> result;
        for (const auto& p : freq) {
            if (p.second > require) {
                result.push_back(p.first);
            }
        }

        return result;
    }
};
