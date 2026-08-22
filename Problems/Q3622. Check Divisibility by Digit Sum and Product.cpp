class Solution {
    int digitSum(int n) {
        int res = 0;
        while (n > 0) {
            res += n % 10;
            n = n / 10;
        }
        return res;
    }

    int digitProduct(int n) {
        int res = 1;
        while (n > 0) {
            res *= n % 10;
            n = n / 10;
        }
        return res;
    }

public:
    bool checkDivisibility(int n) {
        int s = digitSum(n);
        int p = digitProduct(n);

        return n % (s + p) == 0;
    }
};
