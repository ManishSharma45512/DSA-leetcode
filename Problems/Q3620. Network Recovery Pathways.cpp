class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        if (edges.empty()) return -1;

        // 1. Build adjacency list and compute in-degrees
        vector<vector<pair<int, int>>> graph(n);
        vector<int> in_degree(n, 0);
        vector<int> unique_costs;

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], cost = edge[2];
            graph[u].push_back({v, cost});
            in_degree[v]++;
            unique_costs.push_back(cost);
        }

        // 2. Perform Topological Sort
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 0) q.push(i);
        }

        vector<int> topo_order;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo_order.push_back(u);

            for (const auto& edge : graph[u]) {
                int v = edge.first;
                in_degree[v]--;
                if (in_degree[v] == 0) q.push(v);
            }
        }

        // Sort and remove duplicate edge costs for binary search bounds
        sort(unique_costs.begin(), unique_costs.end());
        unique_costs.erase(unique(unique_costs.begin(), unique_costs.end()), unique_costs.end());

        // 3. Binary Search over the unique costs
        int low = 0;
        int high = static_cast<int>(unique_costs.size()) - 1;
        int max_score = -1;
        const long long INF = 1e16; // Safely larger than maximum possible path cost

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int current_threshold = unique_costs[mid];

            // Inline DP / Shortest Path evaluation for the current threshold
            vector<long long> dist(n, INF);
            dist[0] = 0;

            for (int u : topo_order) {
                if (dist[u] == INF) continue;
                
                // If an intermediate node is offline, we cannot route through it
                if (u != 0 && u != n - 1 && !online[u]) continue;

                for (const auto& edge : graph[u]) {
                    int v = edge.first;
                    long long cost = edge.second;

                    // Only traverse edges that meet or exceed our bottleneck target
                    if (cost >= current_threshold) {
                        if (dist[u] + cost < dist[v]) {
                            dist[v] = dist[u] + cost;
                        }
                    }
                }
            }

            // Check if node n-1 is reachable within budget k
            if (dist[n - 1] <= k) {
                max_score = current_threshold; 
                low = mid + 1; // Valid path found, try to maximize the score threshold
            } else {
                high = mid - 1; // Cost exceeded or unreachable, lower the threshold
            }
        }

        return max_score;
    }
};
