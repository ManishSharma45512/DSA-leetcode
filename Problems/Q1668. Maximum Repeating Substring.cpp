class Solution {

    bool isEqual(string s, string t) {
        if (s.length() != t.length()) return false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) return false;
        }

        return true;
    }

public:
    int maxRepeating(string sequence, string word) {
        if (sequence.length() < word.length() || sequence.length() == 0) return 0;

        int maxCount = 0;
        int wordLen = word.length();
        int seqLen = sequence.length();

        for (int i = 0; i <= seqLen - wordLen; i++) {
            int currentCount = 0;
            int j = i;

            while (j + wordLen <= seqLen) {
                string sub = sequence.substr(j, wordLen);
                if (isEqual(word, sub)) {
                    currentCount++;
                    j += wordLen;
                } else {
                    break;// Stop when the chain breaks
                }
            }

            maxCount = max(maxCount, currentCount);
        }

        return maxCount;
    }
};
