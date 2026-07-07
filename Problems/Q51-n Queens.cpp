class Solution {
private:
    vector<vector<string>> ans;
    vector<bool> cols, diag1, diag2;

    void backtrack(int row, int n, vector<string>& board) {
        // Base case
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            // Check for attack
            if (cols[col] || diag1[row - col + n] || diag2[row + col]) {
                continue;
            }

            // Place the queen
            board[row][col] = 'Q';
            cols[col] = diag1[row - col + n] = diag2[row + col] = true;

            // Recurse towards the next row
            backtrack(row + 1, n, board);

            // Backtrack: Remove the queen and reset tracking
            board[row][col] = '.';
            cols[col] = diag1[row - col + n] = diag2[row + col] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();


        cols.assign(n, false);
        diag1.assign(2 * n, false);
        diag2.assign(2 * n, false);

        // making empty board
        vector<string> board(n, string(n, '.'));

        backtrack(0, n, board);
        return ans;
    }
};
