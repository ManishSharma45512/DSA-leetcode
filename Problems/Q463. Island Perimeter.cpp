class Solution {
    void helper(vector<vector<int>>& grid, int i, int j, int m, int n, int& p) {

        if (grid[i][j] == 1 && i >= 0 && i < m && j >= 0 && j < n) {
            
            // Up: if out of grid OR neighboring cell is water -> wall
            if (i - 1 < 0 || grid[i - 1][j] == 0) p++;

            // Down: if out of grid OR neighboring cell is water -> wall
            if (i + 1 == m || grid[i + 1][j] == 0) p++;

            // Left: if out of grid OR neighboring cell is water -> wall
            if (j - 1 < 0 || grid[i][j - 1] == 0) p++;

            // Right: if out of grid OR neighboring cell is water -> wall
            if (j + 1 == n || grid[i][j + 1] == 0) p++;
        }

        return; 
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int p = 0; // initial perimeter
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                helper(grid, i, j, m, n, p);
            }
        }

        return p;
    }
};
