class Solution {
    long long MOD = 1e9 + 7;
    vector<vector<long long>> comb;

    long long dfs(const vector<int>& nums) {
        if (nums.size() <= 2) {
            return 1;
        }

        int root = nums[0];
        vector<int> left, right;

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long left_ways = dfs(left);
        long long right_ways = dfs(right);

        // Pick left.size() positions out of (left.size() + right.size()) available slots
        long long total_combinations = comb[left.size() + right.size()][left.size()];

        long long result = (total_combinations * left_ways) % MOD;
        result = (result * right_ways) % MOD;

        return result;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        // Precompute Pascal's triangle for combinations C(n, k) modulo 1e9 + 7
        comb.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        // Subtract 1 to exclude the original array ordering
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};
