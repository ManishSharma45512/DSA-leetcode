class Solution {
public:
    long long power(int n, long long val = 1) { 
        if (val >= n) return val;//Recursion base case

        long long res = 2 * val;
        return power(n, res);
    }
    
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;//BASE CASE

        if (n == power(n, 1)) return true;

        return false;
    }
};
