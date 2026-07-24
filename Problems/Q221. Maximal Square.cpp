class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        // 2D vectors for horizontal and vertical consecutive 1s
        vector<vector<int>> hArea(rows, vector<int>(cols, 0));
        vector<vector<int>> vArea(rows, vector<int>(cols, 0));
        
        vector<vector<int>> square(rows, vector<int>(cols, 0));

        
        for (int i = 0; i < rows; i++) {// Calculate Horizontal Area
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    hArea[i][j] = (j == 0) ? 1 : hArea[i][j - 1] + 1;
                } else {
                    hArea[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < cols; j++) {// Calculate Vertical Area
            for (int i = 0; i < rows; i++) {
                if (matrix[i][j] == '1') {
                    vArea[i][j] = (i == 0) ? 1 : vArea[i - 1][j] + 1;
                } else {
                    vArea[i][j] = 0;
                }
            }
        }

        int maxSide = 0;

        for (int i = 0; i < rows; i++) {//Combining hArea, vArea, AND the top-left diagonal interior check
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {// Base case
                        square[i][j] = 1;
                    } else {
                        int borderLimit = min(hArea[i][j], vArea[i][j]);
                        square[i][j] = min(borderLimit, square[i - 1][j - 1] + 1);
                    }
                    maxSide = max(maxSide, square[i][j]);
                }
            }
        }

        return maxSide * maxSide;//maximum area
    }
};
