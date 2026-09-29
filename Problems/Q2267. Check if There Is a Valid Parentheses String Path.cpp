class Solution {
    int m, n;
    // visited[r][c][bal] tracks whether state (r, c, bal) has already been explored
    bool visited[101][101][205];

    bool dfs(int r, int c, int balance, const vector<vector<char>>& grid) {
        // Update balance for the current cell
        balance += (grid[r][c] == '(' ? 1 : -1);

        // Parentheses string is invalid if balance drops below 0
        if (balance < 0) return false;

        // Pruning: if open '(' count exceeds remaining steps, balance can never reach 0
        int remaining_steps = (m - 1 - r) + (n - 1 - c);
        if (balance > remaining_steps) return false;

        // Destination reached: valid only if perfectly balanced
        if (r == m - 1 && c == n - 1) {
            return balance == 0;
        }

        // Return false if this state has already been computed and failed
        if (visited[r][c][balance]) return false;
        visited[r][c][balance] = true;

        // Move Down
        if (r + 1 < m && dfs(r + 1, c, balance, grid)) {
            return true;
        }

        // Move Right
        if (c + 1 < n && dfs(r, c + 1, balance, grid)) {
            return true;
        }

        return false;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // 1. Total path length (m + n - 1) must be even
        if ((m + n - 1) % 2 != 0) return false;

        // 2. Starting cell must be '(' and ending cell must be ')'
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        // Reset visited table
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k <= (m + n); ++k) {
                    visited[i][j][k] = false;
                }
            }
        }

        return dfs(0, 0, 0, grid);
    }
};
