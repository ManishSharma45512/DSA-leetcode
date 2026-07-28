class Solution {
    int getAlphabetPosition(char ch) {
        char lowerChar = tolower(ch);
        return lowerChar - 'a'; // 0-based index ('a' = 0, 'b' = 1, ...)
    }

public:
    string smallestPalindrome(string s) {
        if (s.length() == 1) return s; // Base case

        vector<int> alphabetFreq(26, 0);

        for (char c : s) {
            alphabetFreq[getAlphabetPosition(c)]++;
        }

        string leftHalf = "";
        char middleChar = '\0';

        for (int i = 0; i < 26; i++) {
            char currentChar = (char)('a' + i);

            // Add half of the available pairs to the left half
            while (alphabetFreq[i] > 1) {
                leftHalf += currentChar;
                alphabetFreq[i] -= 2;
            }

            if (alphabetFreq[i] == 1) {
                middleChar = currentChar;
                alphabetFreq[i]--;
            }
        }

        string rightHalf = string(leftHalf.rbegin(), leftHalf.rend());

        
        if (middleChar != '\0') {//palindrome if mid exist left+mid+right
            return leftHalf + middleChar + rightHalf;
        }

        return leftHalf + rightHalf;//mid not exist so simple left + right(reverse of left)
    }
};
