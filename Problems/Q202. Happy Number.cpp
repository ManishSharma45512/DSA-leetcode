class Solution {
    bool helper(int n, unordered_set<int>& visited) {
        if (n == 1) return true;//Base Case
        if (visited.count(n)) return false; // Cycle repeated

        visited.insert(n);

        long long sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return helper(sum, visited);
    }

public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        return helper(n, visited);
    }
};
