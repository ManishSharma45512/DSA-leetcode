class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<int> ans(m);

        // Min-heap for available servers: stores {weight, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> available;
        
        // Min-heap for busy servers: stores {free_time, weight, index}
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> busy;

        // Initialize all servers as available
        for (int i = 0; i < n; ++i) {
            available.push({servers[i], i});
        }

        long long current_time = 0;

        for (int i = 0; i < m; ++i) {
            // Time cannot go backwards, but can jump to when the next task arrives (i)
            // or when a server becomes free.
            current_time = max(current_time, (long long)i);

            // Free up any servers whose task has finished by current_time
            while (!busy.empty() && get<0>(busy.top()) <= current_time) {
                auto [free_time, weight, index] = busy.top();
                busy.pop();
                available.push({weight, index});
            }

            // If no servers are available, jump time to when the earliest server frees up
            if (available.empty()) {
                current_time = get<0>(busy.top());
                while (!busy.empty() && get<0>(busy.top()) <= current_time) {
                    auto [free_time, weight, index] = busy.top();
                    busy.pop();
                    available.push({weight, index});
                }
            }

            // Assign the task to the best available server
            auto [weight, index] = available.top();
            available.pop();

            ans[i] = index;
            // Push the server to busy with its new free time
            busy.push({current_time + tasks[i], weight, index});
        }

        return ans;
    }
};
