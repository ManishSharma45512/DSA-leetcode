class Solution {
private:
    bool isValid(const string& str) {
        int balance = 0;
        for (char c : str) {
            if (c == '(') balance++;
            else if (c == ')') {
                balance--;
                if (balance < 0) return false;
            }
        }
        return balance == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);
        bool foundValidLevel = false;

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                string curr = q.front();
                q.pop();

                if (isValid(curr)) {
                    result.push_back(curr);
                    foundValidLevel = true;
                }

                // If we already found valid strings at this level, do not generate next level
                if (foundValidLevel) continue;

                for (int j = 0; j < curr.length(); j++) {
                    if (curr[j] != '(' && curr[j] != ')') continue;

                    // Form candidate by removing curr[j]
                    string nextStr = curr.substr(0, j) + curr.substr(j + 1);
                    if (!visited.count(nextStr)) {
                        visited.insert(nextStr);
                        q.push(nextStr);
                    }
                }
            }

            if (foundValidLevel) break;
        }

        return result;
    }
};
