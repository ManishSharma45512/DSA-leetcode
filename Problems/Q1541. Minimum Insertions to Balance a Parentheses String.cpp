class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int needed_right = 0;

        for (char c : s) {
            if (c == '(') {
                if (needed_right % 2 != 0) {
                    ans++;
                    needed_right--;
                }
                needed_right += 2;
            } else {
                needed_right--;
                if (needed_right < 0) {
                    ans++;
                    needed_right += 2;
                }
            }
        }

        return ans + needed_right;
    }
};
