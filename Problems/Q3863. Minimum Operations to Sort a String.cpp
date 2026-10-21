class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        // Check if the string is already sorted
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        // A proper substring of length 2 has length at most 1, which cannot reorder anything
        if (n == 2) {
            return -1;
        }

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // 1 operation: minimum is already at the start, or maximum is already at the end
        if (s.front() == mn || s.back() == mx) {
            return 1;
        }

        // 2 operations: minimum or maximum exists anywhere in the interior s[1 ... n-2]
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }

        // 3 operations: mn only exists at s.back() and mx only exists at s.front()
        return 3;
    }
};
