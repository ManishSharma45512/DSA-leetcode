class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.length();
        int ps = p.length();
        
        // dp[i][j] will be true if s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp(ns + 1, vector<bool>(ps + 1, false));
        
        // Base case: empty string matches empty pattern
        dp[0][0] = true;
        
        // Deal with patterns like a*, a*b*, or a*b*c* matching an empty string
        for (int j = 2; j <= ps; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        // DP table
        for (int i = 1; i <= ns; i++) {
            for (int j = 1; j <= ps; j++) {
                
                // If characters match, or pattern has a '.'
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                // If we encounter a '*'
                else if (p[j - 1] == '*') {
                    // Case 1: Match 0 times (ignore the character and the '*')
                    dp[i][j] = dp[i][j - 2];
                    
                    // Case 2: Match 1 or more times (if preceding character matches)
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        
        return dp[ns][ps];
    }
};
