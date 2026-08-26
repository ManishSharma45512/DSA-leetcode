class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        int ones = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            if (s[r] == '1') {
                ones++;
            }

            // Once we have k ones, minimize window from the left
            while (ones == k) {
                // Discard leading zeros if present
                if (s[l] == '0') {
                    l++;
                    continue;
                }

                // Window [l, r] starts and ends with '1' and has exactly k ones
                string curr = s.substr(l, r - l + 1);

                if (ans.empty() || curr.size() < ans.size() || (curr.size() == ans.size() && curr < ans)) {
                    ans = curr;
                }

                // Shrink past the first '1' to continue searching
                ones--;
                l++;
            }
        }

        return ans;
    }
};
