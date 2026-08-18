class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> subarrayCount;

        
        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> uniqueInWindow;
            for (int j = i; j < i + k; j++) {
                uniqueInWindow.insert(nums[j]);
            }
            for (int val : uniqueInWindow) {
                subarrayCount[val]++;
            }
        }

        int maxVal = -1;
        for (auto& [val, count] : subarrayCount) {
            if (count == 1) {
                maxVal = max(maxVal, val);
            }
        }

        return maxVal;
    }
};
