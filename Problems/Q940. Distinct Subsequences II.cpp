class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<long long> last_added(26, 0);
        long long total = 0;

        for (char ch : s) {
            int idx = ch - 'a';
    
            long long new_count = (total + 1) % MOD;
            
            total = (total + new_count - last_added[idx]) % MOD;
            if (total < 0) {
                total += MOD;
            }
            
            last_added[idx] = new_count;
        }

        return total;
    }
};
