class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int start_x = -1, start_y = -1;
        vector<pair<int, int>> litters;
        
        // Find starting position and assign unique IDs to each litter
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    start_x = i;
                    start_y = j;
                } else if (classroom[i][j] == 'L') {
                    litters.push_back({i, j});
                }
            }
        }
        
        int k = litters.size();
        if (k == 0) return 0;
        int target_mask = (1 << k) - 1;
        
        // DP table: dp[r][c][mask] stores the maximum remaining energy achieved
        int dp[20][20][1 << 10];
        memset(dp, -1, sizeof(dp));
        
        // Queue stores: {r, c, mask, current_energy, moves}
        queue<vector<int>> q;
        q.push({start_x, start_y, 0, energy, 0});
        dp[start_x][start_y][0] = energy;
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            int r = curr[0], c = curr[1], mask = curr[2], rem_energy = curr[3], moves = curr[4];
            
            // If we found all litters, return the step count
            if (mask == target_mask) {
                return moves;
            }
            
            // If there's no energy to make the next step, skip
            if (rem_energy == 0) continue;
            
            for (int dir = 0; dir < 4; dir++) {
                int nr = r + dx[dir];
                int nc = c + dy[dir];
                
                // Boundary and obstacle check
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') {
                    continue;
                }
                
                int next_mask = mask;
                int next_energy = rem_energy - 1;
                
                // If the new cell has litter, collect it and update mask
                if (classroom[nr][nc] == 'L') {
                    for (int i = 0; i < k; i++) {
                        if (litters[i].first == nr && litters[i].second == nc) {
                            next_mask |= (1 << i);
                            break;
                        }
                    }
                }
                // If it's a reset point, refill energy to max capacity
                else if (classroom[nr][nc] == 'R') {
                    next_energy = energy;
                }
                
                // DP check: only proceed if this path gives more energy for the same state
                if (next_energy > dp[nr][nc][next_mask]) {
                    dp[nr][nc][next_mask] = next_energy;
                    q.push({nr, nc, next_mask, next_energy, moves + 1});
                }
            }
        }
        
        return -1;
    }
};
