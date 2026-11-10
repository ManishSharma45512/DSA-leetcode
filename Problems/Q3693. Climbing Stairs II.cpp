#include <vector>
#include <algorithm>

class Solution {
public:
    long long climbStairs(int n, vector<int>& costs) {
        // dp[i] stores the minimum cost to reach step i
        vector<long long> dp(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            long long min_cost = -1;
            
            // Try jumping from i - 1
            if (i - 1 >= 0) {
                long long cost = dp[i - 1] + costs[i - 1] + 1; // (1)^2 = 1
                min_cost = cost;
            }
            
            // Try jumping from i - 2
            if (i - 2 >= 0) {
                long long cost = dp[i - 2] + costs[i - 1] + 4; // (2)^2 = 4
                if (min_cost == -1 || cost < min_cost) {
                    min_cost = cost;
                }
            }
            
            // Try jumping from i - 3
            if (i - 3 >= 0) {
                long long cost = dp[i - 3] + costs[i - 1] + 9; // (3)^2 = 9
                if (min_cost == -1 || cost < min_cost) {
                    min_cost = cost;
                }
            }
            
            dp[i] = min_cost;
        }
        
        return dp[n];
    }
};
