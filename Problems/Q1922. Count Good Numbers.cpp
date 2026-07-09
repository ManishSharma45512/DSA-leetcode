class Solution {
private:
    long long MOD = 1000000007;

    // A fast O(log y) function to compute (x^y) % MOD using binary exponentiation
    long long power(long long x, long long y) {
        long long res = 1;
        x = x % MOD;
        while (y > 0) {
            // If y is odd, multiply x with the result
            if (y % 2 == 1) {
                res = (res * x) % MOD;
            }
            // y must be even now, shift it down and square the base
            y = y / 2;
            x = (x * x) % MOD;
        }
        return res;
    }

public:
    int countGoodNumbers(long long n) {
        if (n == 0) return 0; // Base Case


        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        // Calculate (5^evenPositions) % MOD
        long long evenChoices = power(5, evenPositions);
        
        // Calculate (4^oddPositions) % MOD
        long long primeChoices = power(4, oddPositions);

        // Combine them together cleanly under the modulo constraint
        long long result = (evenChoices * primeChoices) % MOD;

        return (int)result;
    }
};
