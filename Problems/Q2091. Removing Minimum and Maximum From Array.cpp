class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;//Base Case

        int minIdx = 0, maxIdx = 0;
        for (int i = 1; i < n; i++) {//O(N)
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }

        int l = min(minIdx, maxIdx);
        int r = max(minIdx, maxIdx);

        int frontOnly = r + 1;

        int backOnly = n - l;

        int bothEnds = (l + 1) + (n - r);

        return min({frontOnly, backOnly, bothEnds});
    }
};
