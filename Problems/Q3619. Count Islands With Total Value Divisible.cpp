class Solution {
    long long dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int m, int n) {
        // Base case: out of bounds, already visited, or water (0)
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || grid[i][j] == 0) {
            return 0;
        }
        
        visited[i][j] = true;
        long long current_sum = grid[i][j];
        
        // Explore all 4 adjacent directions
        current_sum += dfs(grid, visited, i + 1, j, m, n);
        current_sum += dfs(grid, visited, i - 1, j, m, n);
        current_sum += dfs(grid, visited, i, j + 1, m, n);
        current_sum += dfs(grid, visited, i, j - 1, m, n);
        
        return current_sum;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If it's land and hasn't been visited yet, explore the island
                if (grid[i][j] > 0 && !visited[i][j]) {
                    long long island_sum = dfs(grid, visited, i, j, m, n);
                    if (island_sum % k == 0) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};
