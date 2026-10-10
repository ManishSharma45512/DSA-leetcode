class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        
        int max_diff = 0;
        for (int i = 0; i < n; i++) {
            max_diff = max(max_diff, abs(nums1[i] - nums2[i]));
        }
        
        if (max_diff == 0) return 0;
        
        vector<int> count(max_diff + 1, 0);
        for (int i = 0; i < n; i++) {
            count[abs(nums1[i] - nums2[i])]++;
        }
        
        // Greedily reduce the highest differences
        for (int v = max_diff; v > 0 && k > 0; v--) {
            if (count[v] == 0) continue;
            
            if (k >= count[v]) {
                k -= count[v];
                count[v - 1] += count[v];
                count[v] = 0;
            } else {
                count[v - 1] += k;
                count[v] -= k;
                k = 0;
            }
        }
        
        long long ans = 0;
        for (long long v = 1; v <= max_diff; v++) {
            if (count[v] > 0) {
                ans += (long long)count[v] * v * v;
            }
        }
        
        return ans;
    }
};
