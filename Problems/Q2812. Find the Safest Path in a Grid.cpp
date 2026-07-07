#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Quick exit if start or end is blocked by a thief
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return 0;
        }
        
        // -----------------------------------------------------------------
        // PHASE 1: Multi-source BFS to calculate Manhattan distance to nearest thief
        // -----------------------------------------------------------------
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        
        // Push all thieves into the queue initialization
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    dist[r][c] = 0;
                    q.push({r, c});
                }
            }
        }
        
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        // -----------------------------------------------------------------
        // PHASE 2: Modified Dijkstra's using a Max-Heap to find the safest path
        // -----------------------------------------------------------------
        // Priority Queue stores: {safeness_factor, {r, c}}
        priority_queue<pair<int, pair<int, int>>> max_heap;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        max_heap.push({dist[0][0], {0, 0}});
        visited[0][0] = true;
        
        while (!max_heap.empty()) {
            auto [safeness, cell] = max_heap.top();
            int r = cell.first;
            int c = cell.second;
            max_heap.pop();
            
            // Reached destination: because it's a Max-Heap, this is guaranteed 
            // to be the maximum bottleneck safeness factor possible.
            if (r == n - 1 && c == n - 1) {
                return safeness;
            }
            
            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    // The safeness of a path is the MINIMUM value along its cells
                    int next_safeness = min(safeness, dist[nr][nc]);
                    max_heap.push({next_safeness, {nr, nc}});
                }
            }
        }
        
        return 0;
    }
};
