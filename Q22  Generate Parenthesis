class Solution {
private:
    void backtrack(vector<string>& result, string current, int open_count, int close_count, int max_pairs) {
        // Base case: If the string reaches the max length (2 * n)
        if (current.length() == 2 * max_pairs) {
            result.push_back(current);
            return;
        }

        // Rule 1: Add an opening parenthesis if we haven't used all n of them
        if (open_count < max_pairs) {
            backtrack(result, current + "(", open_count + 1, close_count, max_pairs);
        }

        // Rule 2: Add a closing parenthesis if it doesn't outnumber the opening ones
        if (close_count < open_count) {
            backtrack(result, current + ")", open_count, close_count + 1, max_pairs);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};
