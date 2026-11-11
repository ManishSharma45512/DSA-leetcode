class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, long long need1, long long need2) {
        // Lambda function to calculate total cost given 'i' type 3 items
        auto get_cost = [&](long long i) {
            long long rem1 = max(0LL, need1 - i);
            long long rem2 = max(0LL, need2 - i);
            return i * costBoth + rem1 * cost1 + rem2 * cost2;
        };

        // Evaluate cost at the three critical breakpoints
        long long ans = get_cost(0);
        ans = min(ans, get_cost(min(need1, need2)));
        ans = min(ans, get_cost(max(need1, need2)));

        return ans;
    }
};
