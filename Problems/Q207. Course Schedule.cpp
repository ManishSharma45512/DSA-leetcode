class Solution {
    bool hasCycle(int node, vector<vector<int>>& adj, vector<int>& state) {
        state[node] = 1; // Mark as visiting

        for (int neighbor : adj[node]) {
            if (state[neighbor] == 1) return true;  // Cycle detected
            if (state[neighbor] == 0) {
                if (hasCycle(neighbor, adj, state)) return true;
            }
        }

        state[node] = 2; // Mark as fully processed
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> state(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (hasCycle(i, adj, state)) return false; // Found a cycle
            }
        }

        return true;
    }
};
