class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0'; // Converts char '1' or '0' to int 1 or 0
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            ans += to_string(sum % 2);//sum%2 tells us if current number is 0 or 1

            carry = sum / 2;// sum/2 tells us if we need to carry a number or not
        }

        
        reverse(ans.begin(), ans.end());//answer is reverse so we make is forward
        return ans;
    }
};
