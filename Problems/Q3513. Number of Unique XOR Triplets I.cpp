class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        
        
        if (n < 3) return n;// Base cases
        
        int bits = __lg(n) + 1;//total bits=2^([log(n)]+1)
        
        return 1 << bits;// bitwise operator
    }
};
