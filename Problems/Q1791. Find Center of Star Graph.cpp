class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // The center node must appear in both edge[0] and edge[1]
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0];
        }
        return edges[0][1];
    }
};
