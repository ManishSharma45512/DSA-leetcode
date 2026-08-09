class Solution {
    int n;
    vector<int> suffixSum;
    vector<vector<int>> dp;

    int solve(int i, int m) {
        
        if (i + 2 * m >= n) {// Base Case
            return suffixSum[i];
        }

        // Return cached result
        if (dp[i][m] != -1) {
            return dp[i][m];
        }

        int maxStones = 0;

        // Try taking X piles where 1 <= X <= 2 * m
        for (int x = 1; x <= 2 * m; x++) {
            // Player gets total remaining stones MINUS whatever optimal opponent gets
            int opponentStones = solve(i + x, max(m, x));
            int currentStones = suffixSum[i] - opponentStones;

            maxStones = max(maxStones, currentStones);
        }

        return dp[i][m] = maxStones;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        
        //Precalculate Suffix Sums
        suffixSum.resize(n);
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        //Initialize Memoization Table DP[i][m]
        //m ranges to n
        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1); // Alice starts at index 0 with M = 1
    }
};
