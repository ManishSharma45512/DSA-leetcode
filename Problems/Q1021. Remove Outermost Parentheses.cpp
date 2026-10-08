class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int opened = 0;

        for (char c : s) {
            if (c == '(') {
                if (opened > 0) {
                    result.push_back(c);
                }
                opened++;
            } else { // c == ')'
                opened--;
                if (opened > 0) {
                    result.push_back(c);
                }
            }
        }

        return result;
    }
};
