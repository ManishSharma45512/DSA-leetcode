class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        vector<int> bit_count(30, 0);

        // Count bit frequencies across all numbers
        for (int x : nums) {
            for (int b = 0; b < 30; b++) {
                if ((x >> b) & 1) {
                    bit_count[b]++;
                }
            }
        }

        long long total_sum = 0;

        // Greedily build the top k largest numbers
        for (int i = 0; i < k; i++) {
            long long val = 0;
            for (int b = 0; b < 30; b++) {
                if (bit_count[b] > 0) {
                    val |= (1LL << b);
                    bit_count[b]--;
                }
            }
            total_sum = (total_sum + (val % MOD) * (val % MOD)) % MOD;
        }

        return total_sum;
    }
};
