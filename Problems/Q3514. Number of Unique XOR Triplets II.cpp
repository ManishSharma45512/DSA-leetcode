class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        
        
        int maxVal = 0;
        for (int x : nums) {// maximum element to determine maximum bit bound T
            maxVal = max(maxVal, x);
        }

        // T is the smallest power of 2 greater than maxVal
        int T = 1;
        while (T <= maxVal) {
            T <<= 1;
        }

        vector<bool> s1(T, false); // Stores unique pair XORs
        vector<bool> s2(T, false); // Stores unique triplet XORs

        // Compute all pair XORs (i <= j)
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                s1[nums[i] ^ nums[j]] = true;
            }
        }

        // Combine pair XORs with the 3rd element
        for (int x = 0; x < T; x++) {
            if (s1[x]) {
                for (int num : nums) {
                    s2[x ^ num] = true;
                }
            }
        }

        // Count total unique triplet values
        int count = 0;
        for (int i = 0; i < T; i++) {
            if (s2[i]) count++;
        }

        return count;
    }
};
