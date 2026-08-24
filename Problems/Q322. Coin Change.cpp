class Solution {
    int helper(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        if (dp[amount] != -2) return dp[amount];

        int minCoins = INT_MAX;

        for (int i = 0; i < coins.size(); i++) {
            if (coins[i] <= amount) {
                int res = helper(coins, amount - coins[i], dp);
                if (res != -1) {
                    minCoins = min(minCoins, 1 + res);
                }
            }
        }

        return dp[amount] = (minCoins == INT_MAX) ? -1 : minCoins;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -2);
        return helper(coins, amount, dp);
    }
};
