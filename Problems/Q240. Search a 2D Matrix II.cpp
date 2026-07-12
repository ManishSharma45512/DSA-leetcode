class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row = 0;
        int col = n - 1;
        
        // Loop runs until we step out of the matrix boundaries
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true; // Base Case
            } 
            else if (matrix[row][col] > target) {
                col--; // Current value>target -> eliminate this column
            } 
            else {
                row++; // Current value <small -> eliminate this row
            }
        }
        
        return false; //Target doesn't exist
    }
};
