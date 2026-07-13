class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, int i, int j, int n, int m, int index) {
        if (index == word.size()) return true;

        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[index]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';//visited marked

        bool found = helper(board, word, i + 1, j, n, m, index + 1) ||
                     helper(board, word, i - 1, j, n, m, index + 1) ||
                     helper(board, word, i, j + 1, n, m, index + 1) ||
                     helper(board, word, i, j - 1, n, m, index + 1);

        
        board[i][j] = temp;// Backtrack: Restore the original character for other search paths

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty()) return false;
        
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (helper(board, word, i, j, n, m, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
