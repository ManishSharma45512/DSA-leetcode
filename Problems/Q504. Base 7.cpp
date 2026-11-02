class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        
        string s = "";
        bool isNegative = num < 0;
        long long n = abs((long long)num);// Using long long to prevent overflow with INT_MIN
        
        while (n > 0) {
            s += to_string(n % 7);
            n /= 7;
        }
        
        if (isNegative) {
            s += "-";
        }
        
        reverse(s.begin(), s.end());
        return s;
    }
};
