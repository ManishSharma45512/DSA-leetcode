class Solution {
    // Helper function to calculate distinct permutations of remaining characters:
    // (len!) / (c1! * c2! * ... * c26!) capped at k to avoid overflow
    long long countWays(const vector<int>& halfFreq, int remainingLen, long long kCap) {
        long long ways = 1;
        int currentLen = 0;

        for (int count : halfFreq) {
            for (int i = 1; i <= count; i++) {
                currentLen++;
                ways = ways * currentLen / i;
                if (ways > kCap) {
                    return kCap + 1; // Cap to prevent overflow
                }
            }
        }
        return ways;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<int> halfFreq(26, 0);
        int halfLen = 0;
        char midChar = '\0';

        // Halve character frequencies for the left half
        for (int i = 0; i < 26; i++) {
            halfFreq[i] = freq[i] / 2;
            halfLen += halfFreq[i];
            if (freq[i] % 2 != 0) {
                midChar = (char)('a' + i);
            }
        }

        // Check if k-th permutation is possible
        long long totalWays = countWays(halfFreq, halfLen, k);
        if (totalWays < k) return "";

        string leftHalf = "";

        // Construct the left half character by character
        for (int pos = 0; pos < halfLen; pos++) {
            for (int ch = 0; ch < 26; ch++) {
                if (halfFreq[ch] == 0) continue;

                // Temporarily pick 'ch'
                halfFreq[ch]--;

                long long ways = countWays(halfFreq, halfLen - 1 - pos, k);

                if (ways >= k) {
                    leftHalf += (char)('a' + ch);
                    break; // Move to the next position
                } else {
                    k -= ways;
                    halfFreq[ch]++; // Backtrack and try next character
                }
            }
        }

        // Mirror left half to form right half
        string rightHalf = string(leftHalf.rbegin(), leftHalf.rend());

        if (midChar != '\0') {
            return leftHalf + midChar + rightHalf;
        }

        return leftHalf + rightHalf;
    }
};
