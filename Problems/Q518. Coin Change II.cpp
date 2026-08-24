// unsigned long long is a 64-bit non-negative integer (up to ~1.8e19) that prevents intermediate overflow during additions.
// (int) truncates the 64-bit value back to 32 bits to match the return type; safe because the final answer is guaranteed to fit in int.



class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }

        return (int)dp[amount];
    }
};
