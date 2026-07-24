class Solution {
    int maxSquare(int n) {
        if (n <= 0) return 0;
        int i = 0;
        while ((i + 1) * (i + 1) <= n) { 
            i = i + 1;
        }
        return i; // Returns max square
    }

    int helper(int n, vector<int>& memo) {
        if (n == 0) return 0;
        if (memo[n] != -1) return memo[n];

        int maxRoot = maxSquare(n);
        int minCount = n;

        for (int i = maxRoot; i >= 1; i--) {
            int square = i * i;
            int count = 1 + helper(n - square, memo);
            minCount = min(minCount, count);
        }

        return memo[n] = minCount;
    }

public:
    int numSquares(int n) {
        vector<int> memo(n + 1, -1);
        return helper(n, memo);
    }
};
