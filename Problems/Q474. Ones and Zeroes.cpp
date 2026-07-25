class Solution {
    // Constraints: strs.size() <= 60, m <= 100, n <= 100
    int memo[601][101][101];

    int helper(vector<string>& strs, vector<pair<int, int>>& zeroOneAtIdx, int idx, int m, int n) {
        if (idx == strs.size()) return 0; // Base Case

        if (memo[idx][m][n] != -1) return memo[idx][m][n];

        int zero = zeroOneAtIdx[idx].first;
        int one = zeroOneAtIdx[idx].second;

        int take = 0;
        if (zero <= m && one <= n) {
            take = 1 + helper(strs, zeroOneAtIdx, idx + 1, m - zero, n - one);
        }

        int skip = helper(strs, zeroOneAtIdx, idx + 1, m, n);

        return memo[idx][m][n] = max(take, skip);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // Initialize memo table with -1
        memset(memo, -1, sizeof(memo));

        vector<pair<int, int>> zeroOneAtIdx(strs.size(), {0, 0});

        for (int i = 0; i < strs.size(); i++) {
            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '1') {
                    zeroOneAtIdx[i].second++;
                } else {
                    zeroOneAtIdx[i].first++;
                }
            }
        }

        return helper(strs, zeroOneAtIdx, 0, m, n);
    }
};
