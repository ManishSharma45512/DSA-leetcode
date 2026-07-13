class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        if (nums.empty()) return ans; // Base Case

        int n = nums.size();

        
        unordered_map<int, int> freq;
        for (auto i : nums) {//O(n)
            freq[i]++;
        }

        for (int i = 1; i <= n; i++) {
            if (freq[i] == 0) {//value doesn't exist push in
                ans.push_back(i); '
            }
        }

        return ans;
    }
};
