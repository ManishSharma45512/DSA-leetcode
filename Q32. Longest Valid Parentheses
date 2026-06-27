class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st; 
        
        // Base setup: -1
        st.push(-1); 
        
        int max_len = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                // Opening bracket will should be pushed in the stack
                st.push(i);
            } else {
                // Imediately pop Top element when Closing bracket occurs
                st.pop();

                if (st.empty()) {
                    // if stack is empty means no match value found
                    //so this will be the new invalid boundary
                    st.push(i);
                } else {
                    // If stack is empty, means this is a valid length:
                    // Current Index (i) - Stack's Top Index
                    max_len = max(max_len, i - st.top());
                }
            }
        }

        return max_len;
    }
};
