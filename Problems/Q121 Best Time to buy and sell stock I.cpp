class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int minPriceSoFar = prices[0]; 
        int maxProfitMoney = 0;        

        for (int i = 1; i < prices.size(); i++) {
            
            if (prices[i] < minPriceSoFar) {
                minPriceSoFar = prices[i];
            } 
            
            else {
                int currentProfit = prices[i] - minPriceSoFar;
                if (currentProfit > maxProfitMoney) {
                    maxProfitMoney = currentProfit;
                }
            }
        }

        return maxProfitMoney;
    }
};
