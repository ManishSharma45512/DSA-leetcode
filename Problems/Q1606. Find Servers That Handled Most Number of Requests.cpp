class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> result; // output 

        set<int> available_servers;
        for (int i = 0; i < k; i++) {
            available_servers.insert(i);
        }

        // Use pair<int, int> for {finish_time, server_id}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busyServers;

        vector<int> countRequests(k, 0);

        for (int i = 0; i < arrival.size(); i++) {
            int time = arrival[i];

            // Free up servers whose tasks are completed by the current arrival time
            while (!busyServers.empty() && busyServers.top().first <= time) {
                int server = busyServers.top().second;
                busyServers.pop();
                available_servers.insert(server);
            }

            // If no servers are available at all, drop the request
            if (available_servers.empty()) {
                continue;
            }

            int target = i % k;
            auto it = available_servers.lower_bound(target);

            // If no available server >= target, wrap around to the beginning (0)
            if (it == available_servers.end()) {
                it = available_servers.lower_bound(0);
            }

            int targetServer = *it;
            available_servers.erase(it); // Remove since it's now busy

            busyServers.push({time + load[i], targetServer});
            countRequests[targetServer]++;
        }

        int maxRequest = *max_element(begin(countRequests), end(countRequests));

        for (int i = 0; i < k; i++) {
            if (countRequests[i] == maxRequest) {
                result.push_back(i);
            }
        }

        return result;
    }
};
