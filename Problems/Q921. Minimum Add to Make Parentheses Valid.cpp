class Solution {
public:
    int minAddToMakeValid(std::string s) {
        int open_brackets = 0;
        int added_brackets = 0;

        for (char c : s) {
            if (c == '(') {
                open_brackets++;
            } else {
                if (open_brackets > 0) {
                    open_brackets--;
                } else {
                    added_brackets++;
                }
            }
        }

        return added_brackets + open_brackets;
    }
};
