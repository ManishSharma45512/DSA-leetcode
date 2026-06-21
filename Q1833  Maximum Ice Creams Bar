class Solution {
public:
    int maxIceCream(std::vector<int>& costs, int coins) {
        
        int max_cost = 0;
        for (int c : costs) {
            if (c > max_cost) max_cost = c;
        }
        
        // Create a frequency table
        vector<int> freq(max_cost + 1, 0);
        for (int c : costs) {
            freq[c]++;
        }
        
        int max_ice = 0;
        
        
        for (int price = 1; price <= max_cost; ++price) {
            if (freq[price] == 0) continue;
            
            if (coins < price) break; // Can't even afford one
            
            // Calculate how many we can afford vs how many are available
            long long total_cost_for_all = (long long)price * freq[price];
            
            if (coins >= total_cost_for_all) {
                coins -= total_cost_for_all;
                max_ice += freq[price];
            } else {
                // We can only buy a partial amount of what's available
                int count_we_can_buy = coins / price;
                max_ice += count_we_can_buy;
                break; // Out of coins
            }
        }
        
        return max_ice;
    }
};
