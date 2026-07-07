class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0; // Base Case

        vector<int> digit;
        int sum = 0;
        
        // Loop runs until all digits are peeled off completely
        while (n > 0) { 
            int lastDigit = n % 10;
            
            if (lastDigit != 0) {
                digit.push_back(lastDigit); // Stores digits in reverse order
                sum += lastDigit;
            }
            
            n = n / 10; //Use division to drop the last digit
        }

        // Reconstruct the digits back into their forward order
        long long digitsForward = 0;
        for (int i = digit.size() - 1; i >= 0; i--) {
            digitsForward = digitsForward * 10 + digit[i];
        }

        // Calculate and return the result using your layout
        long long result = digitsForward * sum;
        return result;
    }
};
