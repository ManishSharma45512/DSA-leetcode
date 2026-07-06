class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int sum = 0;
        int sign = 1; 
        int n = s.length();

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            // 1. If the character is a digit, parse the entire multi-digit number
            if (isdigit(ch)) {
                long long num = 0; 
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--; // Step back since the loop increments i once too far
                
                sum += num * sign;
            } 
            // 2. If it's '+', set our sign tracker to positive
            else if (ch == '+') {
                sign = 1;
            } 
            // 3. If it's '-', set our sign tracker to negative (handles unary too)
            else if (ch == '-') {
                sign = -1;
            } 
            // 4. Entering a parenthesis: Save the current state onto the stack
            else if (ch == '(') {
                st.push(sum);
                st.push(sign);
                
                // Reset for the inner sub-expression
                sum = 0;
                sign = 1;
            } 
            // 5. Exiting a parenthesis: Complete sub-expression and merge with previous state
            else if (ch == ')') {
                int prev_sign = st.top(); st.pop();
                int prev_sum = st.top(); st.pop();
                
                sum = prev_sum + (sum * prev_sign);
            }
        }

        return sum;
    }
};
