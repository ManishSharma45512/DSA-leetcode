class Solution {
public:
    string fractionToDecimal(int num, int deno) {
        if (num == 0) return "0";
        string ans = "";
        if ((num < 0) ^ (deno < 0)) ans += "-"; 
        
        long long n = abs((long long)num);//long long to prevent overflow
        long long d = abs((long long)deno);

        if(d == 1) return ans + to_string(n);

        unordered_map<long long, int> repeatafterdecimalIdx;

        long long quotient = n / d;
        long long remainder = n % d;
        n = remainder;

        ans += to_string(quotient);
        
        bool decimalStart = false;
        while(remainder != 0){
            if(n < d && !decimalStart){
                ans += ".";
                decimalStart = true;
            }

            if(decimalStart){ //decimal start we need  to check for repeating value
                if (!repeatafterdecimalIdx.count(remainder)) { // if it doesnot occur yet but now did
                    // we set its idx for if it occur agin we know to add bracket first and last will be in end obviously
                    repeatafterdecimalIdx[remainder] = ans.length(); 
                }
                else { // if occured again
                    ans.insert(repeatafterdecimalIdx[remainder], "("); // add a opening bracket at that idx
                    ans += ")"; // add closing bracket at end
                    break; // stop dividing since the loop is completely found
                }
            }

            n *= 10;
            quotient = n / d;
            remainder = n % d;
            n = remainder;
            
            ans += to_string(quotient);
        }

        return ans;
    }
};
