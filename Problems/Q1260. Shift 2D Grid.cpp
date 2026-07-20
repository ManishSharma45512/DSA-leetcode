class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int size = m * n;

        k %= size; // filterout any useless rotation

        // Create the temporary vector for storing values, properly sized to match grid
        vector<vector<int>> temp(m, vector<int>(n, 0)); 

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // 2D->1D
                int flat_idx = i * n + j;

                // Shift the flat index forward by k and wrap around safely
                int new_flat_idx = (flat_idx + k) % size;

                int new_row = new_flat_idx / n;
                int new_col = new_flat_idx % n;//eg. 7%n=1 means columns is  1st

                //placing the value in temp
                temp[new_row][new_col] = grid[i][j];
            }
        }

        return temp;
    }
};
