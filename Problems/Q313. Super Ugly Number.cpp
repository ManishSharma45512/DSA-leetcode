class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        
        vector<long long> dp(n);
        dp[0] = 1; // 1 is always super ugly

        // Pointers for each prime in the primes array
        vector<int> idxPtr(k, 0);

        for (int i = 1; i < n; i++) {
            long long minNext = LLONG_MAX;

            for (int j = 0; j < k; j++) {
                long long candidate = dp[idxPtr[j]] * primes[j];
                minNext = min(minNext, candidate);
            }

            dp[i] = minNext;

            for (int j = 0; j < k; j++) {
                if (dp[idxPtr[j]] * primes[j] == minNext) {
                    idxPtr[j]++;
                }
            }
        }

        return dp[n - 1];
    }
};
