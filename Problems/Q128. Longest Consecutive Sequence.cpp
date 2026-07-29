class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> freq(nums.begin(), nums.end());
        int maxi = 0;

        for (int num : freq) {
            if (freq.find(num - 1) == freq.end()) {
                int c = num;
                int currentStreak = 1;

                while (freq.find(c + 1) != freq.end()) {
                    c++;
                    currentStreak++;
                }

                maxi = max(maxi, currentStreak);
            }
        }

        return maxi;
    }
};
