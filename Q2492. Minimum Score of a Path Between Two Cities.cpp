class Solution {
public:
    // O(n) - Your Counting Sort algorithm completely untouched
    int getMin(vector<int>& nums) {
        if (nums.empty()) return 0;
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> count(mx + 1, 0);

        for (int x : nums)
            count[x]++;

        for (int i = 0; i <= mx; i++) {
            if (count[i] > 0)
                return i;
        }

        return -1; // Empty array
    }

    int minScore(int n, vector<vector<int>>& roads) {
        if (roads.size() == 0) return 0; // Base Case
        
        
        vector<bool> visited(n + 1, false);
        vector<int> cost(n + 1, INT_MAX);
        
        visited[1] = true;
        cost[1] = 0;

        // Run the flat loop to propagate the visited cities safely
        bool changed = true;
        while (changed) {//O(n)
            changed = false;
            for (int i = 0; i < roads.size(); i++) {
                int u = roads[i][0];
                int v = roads[i][1];
                int weight = roads[i][2];

                // If either city is visited, then both become part of the network
                if (visited[u] || visited[v]) {
                    if (!visited[u]) { visited[u] = true; changed = true; }
                    if (!visited[v]) { visited[v] = true; changed = true; }
                }
            }
        }

        vector<int> minimum_cost;

        //Collect the scores of all roads that touch our visited network
        for (int i = 0; i < roads.size(); i++) {//O(n)
            int u = roads[i][0];
            int v = roads[i][1];
            int weight = roads[i][2];

            
            if (visited[u] && visited[v]) {
                minimum_cost.push_back(weight);
            }
        }

        // Return the minimum path score using your custom counting sort method
        return getMin(minimum_cost);//O(n)
    }
};

//Total TC=O(n)+O(n)+O(n)=3*O(n)=O(3n)=>O(n)
//We did it in O(n) Time Complexity because max constrains are 10^5
