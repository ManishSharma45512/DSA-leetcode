class Solution {
    // Standard GCD and LCM functions
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }

    // Helper to count multiples <= mid using Inclusion-Exclusion
    long long countMultiples(long long mid, vector<int>& coins) {
        int n = coins.size();
        long long totalCount = 0;

        // Iterate through all 2^n - 1 non-empty subsets
        for (int mask = 1; mask < (1 << n); mask++) {
            long long currentLcm = 1;
            int subsetSize = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    currentLcm = lcm(currentLcm, coins[i]);
                    subsetSize++;
                    if (currentLcm > mid) break; // Optimization
                }
            }

            if (subsetSize % 2 == 1) {
                totalCount += (mid / currentLcm);
            } else {
                totalCount -= (mid / currentLcm);
            }
        }

        return totalCount;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long minCoin = *min_element(coins.begin(), coins.end());
        long long high = minCoin * (long long)k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countMultiples(mid, coins) >= k) {
                ans = mid;
                high = mid - 1; // Try to find a smaller valid amount
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};