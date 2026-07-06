class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int maxProfitMoney = 0;        

        // Start from day 1 and compare it directly to the previous day
        for (int i = 1; i < prices.size(); i++) {
            // If the price went up compared to yesterday, lock in the profit!
            if (prices[i] > prices[i - 1]) {
                maxProfitMoney += prices[i] - prices[i - 1];
            }
        }

        return maxProfitMoney;
    }
};
