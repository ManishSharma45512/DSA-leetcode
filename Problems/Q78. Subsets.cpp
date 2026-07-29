class Solution {
    void helper(const vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, int idx) {
        if (idx == nums.size()) {
            res.push_back(curr);
            return;
        }

        //EXCLUDE nums[idx]
        helper(nums, res, curr, idx + 1);

        //INCLUDE nums[idx]
        curr.push_back(nums[idx]);
        helper(nums, res, curr, idx + 1);
        
        // Backtrack
        curr.pop_back(); 
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        
        helper(nums, res, curr, 0);

        return res;
    }
};
