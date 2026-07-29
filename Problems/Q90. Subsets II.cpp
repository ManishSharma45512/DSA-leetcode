class Solution {
    void helper(const vector<int>& nums, map<vector<int>, int>& freqMap, vector<int>& curr, int idx) {
        if (idx == nums.size()) {
            freqMap[curr]++;
            return;
        }

        // EXCLUDE nums[idx]
        helper(nums, freqMap, curr, idx + 1);

        // INCLUDE nums[idx]
        curr.push_back(nums[idx]);
        helper(nums, freqMap, curr, idx + 1);

        // Backtrack
        curr.pop_back();
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        map<vector<int>, int> freqMap;
        vector<int> curr;

        helper(nums, freqMap, curr, 0);


        vector<vector<int>> res;
        for (auto p : freqMap) {
            res.push_back(p.first); // p.first is the unique vector<int>
        }

        return res;
    }
};
