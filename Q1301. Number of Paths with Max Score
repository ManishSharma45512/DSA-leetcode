class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;

        // dp[i][j] = {best_sum, ways}; sum = -1 means unreachable
        vector<vector<pair<long long,long long>>> dp(n, vector<pair<long long,long long>>(n, {-1, 0}));
        dp[n-1][n-1] = {0, 1};  // start at S

        int dirs[3][2] = {{1,0}, {0,1}, {1,1}};  // down, right, down-right

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (board[i][j] == 'X' || (i == n-1 && j == n-1)) continue;

                long long bestSum = -1, ways = 0;
                for (auto& d : dirs) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < n && nj < n && dp[ni][nj].first != -1) {
                        long long s = dp[ni][nj].first, w = dp[ni][nj].second;
                        if (s > bestSum) {
                            bestSum = s;
                            ways = w;
                        } else if (s == bestSum) {
                            ways = (ways + w) % MOD;
                        }
                    }
                }

                if (bestSum == -1) continue;  // no predecessor reaches here

                int val = (board[i][j] == 'E' || board[i][j] == 'S') ? 0 : (board[i][j] - '0');
                dp[i][j] = {bestSum + val, ways};
            }
        }

        long long resSum = dp[0][0].first, resWays = dp[0][0].second;
        if (resSum == -1) return {0, 0};
        return {(int)resSum, (int)resWays};
    }
};
