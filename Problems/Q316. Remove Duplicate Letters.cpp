class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> lastIndex;
        unordered_map<char, bool> visited;
        string result = "";

        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i]] = i;
        }

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (visited[c]) continue;
            while (!result.empty() && result.back() > c && lastIndex[result.back()] > i) {
                visited[result.back()] = false;
                result.pop_back();
            }

            result.push_back(c);
            visited[c] = true;
        }

        return result;
    }
};
