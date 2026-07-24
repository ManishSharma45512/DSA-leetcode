class Solution {
    bool isPalindrome(string s) {
        if (s.length() <= 1) return true;

        int n = s.length();

        for (int i = 0; i < s.length(); i++) {
            if (s[n - i - 1] != s[i]) return false;
        }

        return true;
    }

    void backtrack(int start, string& s, vector<string>& currentPath, vector<vector<string>>& ans) {
        // Base case
        if (start == s.length()) {
            ans.push_back(currentPath);
            return;
        }

        for (int l = 1; start + l <= s.length(); l++) {
            string temp = s.substr(start, l);
            
            if (isPalindrome(temp)) {
                currentPath.push_back(temp);      // Choose
                backtrack(start + l, s, currentPath, ans); // Explore remaining string
                currentPath.pop_back();           // Un-choose (backtrack)
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        if (s.length() == 0) return ans;

        vector<string> currentPath;
        backtrack(0, s, currentPath, ans);

        return ans;
    }
};
