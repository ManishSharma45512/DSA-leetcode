class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int& nodeCount, int& edgeCount) {
        visited[node] = true;
        nodeCount++;
        edgeCount += adj[node].size(); // Sum up all degrees in the component

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, nodeCount, edgeCount);
            }
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int completeComponents = 0;

        // Iterate through all nodes to find components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int nodeCount = 0;
                int edgeCount = 0;

                // Traverse the entire connected component
                dfs(i, adj, visited, nodeCount, edgeCount);

                // Since it's an undirected graph, each edge is counted twice (u->v and v->u)
                // So, actual edges = edgeCount / 2
                // A complete graph requires: nodes * (nodes - 1) / 2 edges
                if (edgeCount == nodeCount * (nodeCount - 1)) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }
};
