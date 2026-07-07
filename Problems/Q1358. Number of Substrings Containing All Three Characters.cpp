class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int count[3] = {0, 0, 0}; //[0,1,2]=[a,b,c]
        int total_substrings = 0;
        int left = 0;
        int n = s.size();

        for (int right = 0; right < n; right++) {
            
            count[s[right] - 'a']++; //ASCII a=97 so if s[right]=b means 98-97=1 which is b index in count

            // While our current window contains at least one 'a', 'b', and 'c'
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                // If s[left...right] is valid, then s[left...right], s[left...right+1], 
                // up to s[left...n-1] are ALL valid. There are (n - right) such substrings!
                total_substrings += (n - right);

                // Shrink the window from the left to find the next boundary
                count[s[left] - 'a']--;
                left++;
            }
        }

        return total_substrings;
    }
};
