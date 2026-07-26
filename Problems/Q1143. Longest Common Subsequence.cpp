class Solution {
    int dp[1001][1001];

    int helper(string& text1, string& text2, int i, int j) {
        // Base case
        if (i == text1.length() || j == text2.length()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        // Characters match!
        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + helper(text1, text2, i + 1, j + 1);
        }

        // Characters don't match -> try skipping in text1 OR text2
        return dp[i][j] = max(helper(text1, text2, i + 1, j), 
                                helper(text1, text2, i, j + 1));
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        for (int i = 0; i <= text1.length(); i++) {
            for (int j = 0; j <= text2.length(); j++) {
                dp[i][j] = -1;
            }
        }
        return helper(text1, text2, 0, 0);
    }
};
