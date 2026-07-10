class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // Step 1: Create a pair of (value, original_index) and sort based on values
        vector<pair<int, int>> sorted_nums(n);
        for (int i = 0; i < n; i++) {
            sorted_nums[i] = {nums[i], i};
        }
        sort(sorted_nums.begin(), sorted_nums.end());

        // Step 2: Map original indices to their new positions in the sorted array
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[sorted_nums[i].second] = i;
        }

        // Calculate the maximum number of steps (log levels) needed
        int max_log = log2(n) + 1;

        // Step 3: Initialize Binary Lifting table up[node][j]
        vector<vector<int>> up(n, vector<int>(max_log, n));

        // Step 4: Compute 2^0 (1 jump) manually using a Two-Pointer approach
        int r = 0;
        for (int l = 0; l < n; l++) {
            while (r < n && sorted_nums[r].first - sorted_nums[l].first <= maxDiff) {
                r++;
            }
            up[l][0] = r - 1; // Furthest valid element index we can reach in 1 jump
        }

        // Step 5: Fill the binary lifting table using Dynamic Programming
        for (int j = 1; j < max_log; j++) {
            for (int i = 0; i < n; i++) {
                int intermediate = up[i][j - 1];
                if (intermediate < n - 1) {
                    up[i][j] = up[intermediate][j - 1];
                } else {
                    up[i][j] = up[i][j - 1];
                }
            }
        }

        // Step 6: Process each query
        vector<int> ans;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            int src = pos[u];
            int dest = pos[v];

            // Since it's an undirected graph, we can always move from left to right
            if (src > dest) {
                swap(src, dest);
            }

            if (src == dest) {
                ans.push_back(0);
                continue;
            }

            int hops = 0;
            int curr = src;

            // Try lifting using descending powers of 2
            for (int j = max_log - 1; j >= 0; j--) {
                if (up[curr][j] < dest) {
                    hops += (1 << j);
                    curr = up[curr][j];
                }
            }

            // After jumping optimally, check if 1 final jump can bridge to the destination
            if (up[curr][0] >= dest) {
                ans.push_back(hops + 1);
            } else {
                ans.push_back(-1); // Destination unreachable
            }
        }

        return ans;
    }
};
