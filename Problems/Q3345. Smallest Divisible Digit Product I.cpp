class Solution {
    int productDigit(int n) {
        int p = 1;
        while (n > 0) {
            int digit = n % 10;
            p *= digit;
            n /= 10;
        }
        return p;
    }

public:
    int smallestNumber(int n, int t) {
        while (productDigit(n) % t != 0) {
            n++;
        }

        return n;
    }
};
