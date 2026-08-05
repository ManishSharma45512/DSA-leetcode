class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        //adjacency list
        vector<vector<int>> adj(n);
        for (const auto& edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }

        //BFS/DFS to find all suspicious methods reachable from k
        vector<bool> isSuspicious(n, false);
        queue<int> q;

        q.push(k);
        isSuspicious[k] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (!isSuspicious[v]) {
                    isSuspicious[v] = true;
                    q.push(v);
                }
            }
        }

        //Check if any non-suspicious method invokes a suspicious method
        bool canRemove = true;
        for (const auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (!isSuspicious[u] && isSuspicious[v]) {
                canRemove = false;
                break;
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            // If we cannot remove, keep all methods; otherwise, keep only non-suspicious ones
            if (!canRemove || !isSuspicious[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};
