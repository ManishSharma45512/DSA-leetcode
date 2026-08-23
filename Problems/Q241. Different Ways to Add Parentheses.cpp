class Solution {
    // using memoization to avoid unnecessary computing of identical expressions
    unordered_map<string, vector<int>> memo;

public:
    vector<int> diffWaysToCompute(string expression) {
        if (memo.count(expression)) { // Base Case: if already computed
            return memo[expression];
        }

        vector<int> result;

        for (int i = 0; i < expression.size(); i++) {
            char op = expression[i];

            if (op == '-' || op == '+' || op == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                // Kept inside the operator block where left and right exist
                for (int l : left) {
                    for (int r : right) {
                        if (op == '+') result.push_back(l + r);
                        else if (op == '-') result.push_back(l - r);
                        else if (op == '*') result.push_back(l * r);
                    }
                }
            }
        }

        // Base Case: if expression is purely a number without any operators
        if (result.empty()) {
            result.push_back(stoi(expression));
        }

        return memo[expression] = result;
    }
};
