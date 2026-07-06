class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        
        for (int i = n - 1; i >= 0; i--) {
            
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            
            
            digits[i] = 0;
        }
        
        // If the loop finishes, it means all digits were 9 (e.g., [9, 9, 9] -> [0, 0, 0])
        // We need to insert a 1 at the very beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
