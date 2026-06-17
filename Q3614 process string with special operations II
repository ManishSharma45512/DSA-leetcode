class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        vector<long long> lengths(n, 0);
        long long len = 0;

        // Pass 1: Just calculate how long the string grows at each step
        for (int i = 0; i < n; i++) {
            if (islower(s[i])) len++;
            else if (s[i] == '*') { if (len > 0) len--; }
            else if (s[i] == '#') len *= 2;
            else if (s[i] == '%') len = len; // Reversal doesn't change length
            
            lengths[i] = len;
        }

        // Quick check: If k is completely out of bounds of the final string
        if (k < 0 || k >= len) return '.';

        // Pass 2: Work backward to find what character lands at index k
        for (int i = n - 1; i >= 0; i--) {
            long long prev_len = (i == 0) ? 0 : lengths[i - 1];

            if (s[i] == '#') {
                // If k falls in the second half of the duplicated string,
                // map it back to the first half
                if (k >= prev_len) {
                    k -= prev_len;
                }
            } 
            else if (s[i] == '%') {
                // If the string was reversed, flip the index k
                k = prev_len - 1 - k;
            } 
            else if (islower(s[i])) {
                // If this character was just added, and k points to it, we found it!
                if (k == prev_len) {
                    return s[i];
                }
            }
        }

        return '.';
    }
};
