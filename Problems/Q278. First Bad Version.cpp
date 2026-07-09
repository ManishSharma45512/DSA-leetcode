// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int st = 1;
        int end = n;
        
        while (st < end) {
            int mid = st + (end - st) / 2; 
            
            if (isBadVersion(mid)) {
                end = mid; // Look left, but keep mid as a candidate
            } else {
                st = mid + 1; // Look right, mid is good so it can't be the answer
            }
        }
        
        // When st == end, we've converged on the first bad version
        return st;
    }
};
