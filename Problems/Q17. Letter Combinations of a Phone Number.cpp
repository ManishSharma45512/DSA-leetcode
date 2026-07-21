class Solution {
    void solve(string digits, int idx, string current, vector<string>& answer, unordered_map<char, vector<char>>& map) {
        // Base Case
        if (idx == digits.length()) {
            answer.push_back(current);
            return;
        }

        char digit = digits[idx];
        vector<char> letters = map[digit];

        for (int i = 0; i < letters.size(); i++) {
            current.push_back(letters[i]);
            solve(digits, idx + 1, current, answer, map); // move to next digit
            current.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; // Base Case

        unordered_map<char, vector<char>> map = {
            {'0', {}},
            {'1', {}},
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };

        vector<string> answer;
        string current = "";

        solve(digits, 0, current, answer, map);

        return answer;
    }
};
