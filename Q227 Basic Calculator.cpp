class Solution {
public:
    int calculate(string s) {
        if(s.length() == 0) return 0;
        
        stack<int> e;  
        int currentNumber = 0;
        char op = '+'; 
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            
            if (c >= '0' && c <= '9') {
                currentNumber = currentNumber * 10 + (c - '0');
            }
            
           
            if ((c == '+' || c == '-' || c == '*' || c == '/') || i == s.length() - 1) {
                if (op == '+') {
                    e.push(currentNumber);
                } 
                else if (op == '-') {
                    e.push(-currentNumber); 
                } 
                else if (op == '*') {
                    int top = e.top();
                    e.pop();
                    e.push(top * currentNumber); 
                } 
                else if (op == '/') {
                    int top = e.top();
                    e.pop();
                    e.push(top / currentNumber);
                }
                
                op = c;
                currentNumber = 0; 
            }
        }
        
        
        int totalResult = 0;
        while (!e.empty()) {
            totalResult += e.top();
            e.pop();
        }
        
        return totalResult;
    }
};
