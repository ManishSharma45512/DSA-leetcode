class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> seen(nums.begin(), nums.end());

        int i= k;
        while (true) {
            if (seen.find(i) == seen.end()) {
                return i;
            }
            i+= k;
        }

        return -1;
    }
};
