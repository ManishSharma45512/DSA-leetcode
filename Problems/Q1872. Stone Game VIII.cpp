class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        //Compute prefix sums in-place
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        int maxDiff = stones[n - 1];//Base case

        //Work backwards from n - 2 down to 1
        for (int i = n - 2; i >= 1; i--) {
            maxDiff = max(maxDiff, stones[i] - maxDiff);
        }

        return maxDiff;
    }
};
