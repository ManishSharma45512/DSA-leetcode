class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<int> ans(m);
        
        // 1. Sort logs by timestamp
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        // 2. Pair queries with their original indices and sort them by query time
        vector<pair<int, int>> indexedQueries(m);
        for (int i = 0; i < m; ++i) {
            indexedQueries[i] = {queries[i], i};
        }
        sort(indexedQueries.begin(), indexedQueries.end());
        
        vector<int> serverCount(n + 1, 0);
        int left = 0, right = 0;
        int numLogs = logs.size();
        int activeServers = 0;
        
        // 3. Sliding window over sorted queries and logs
        for (const auto& q : indexedQueries) {
            int queryTime = q.first;
            int queryIndex = q.second;
            int startTime = queryTime - x;
            
            // Expand window to include logs <= queryTime
            while (right < numLogs && logs[right][1] <= queryTime) {
                int serverId = logs[right][0];
                if (serverCount[serverId] == 0) {
                    activeServers++;
                }
                serverCount[serverId]++;
                right++;
            }
            
            // Shrink window to exclude logs < startTime
            while (left < numLogs && logs[left][1] < startTime) {
                int serverId = logs[left][0];
                serverCount[serverId]--;
                if (serverCount[serverId] == 0) {
                    activeServers--;
                }
                left++;
            }
            
            ans[queryIndex] = n - activeServers;
        }
        
        return ans;
    }
};
