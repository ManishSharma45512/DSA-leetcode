class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 0) return true;

        stack<char> st;

        for (char ch : s) {
            
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            

            else {
                
                if (st.empty()) return false; 

                char topChar = st.top();
                if ((ch == ')' && topChar == '(') ||
                    (ch == '}' && topChar == '{') ||
                    (ch == ']' && topChar == '[')) {
                    st.pop(); //if set of closing bracket found we pop the opening bracket
                } else {
                    return false; //there is a possibility any other bracket can be in the test cases which never makes the stack empty ,So we can exit now;
                }
            }
        }

        //if st.empty()==1 means all pair found and the parenthesis is valid

        //else st.empty()==0 means not all pairs are found so it is a unvalid parenthesis
        return st.empty();
    }
};
