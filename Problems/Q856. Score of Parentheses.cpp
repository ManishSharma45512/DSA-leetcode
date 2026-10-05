class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0); // Base level score accumulator

        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int innerScore = st.top();
                st.pop();

                // If innerScore is 0, it's "()" -> score 1
                // Otherwise it's (A) -> score 2 * innerScore
                int currentScore = (innerScore == 0) ? 1 : 2 * innerScore;

                st.top() += currentScore;
            }
        }

        return st.top();
    }
};
