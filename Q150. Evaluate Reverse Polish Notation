class Solution {
public:
    int eval(int a, int b, string op) {
        if (op == "+") return a + b;
        else if (op == "-") return a - b;
        else if (op == "*") return a * b;
        else return a / b;   
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                st.push(eval(a, b, token));
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
