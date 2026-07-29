class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastSeen;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            if (lastSeen.count(num) && (i - lastSeen[num] <= k)) {
                return true;
            }

            // Update the last seen index for this number
            lastSeen[num] = i;
        }

        return false;
    }
};
