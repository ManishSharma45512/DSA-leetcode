class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        
        res.push_back(intervals[0]);

        
        for (int i = 1; i < intervals.size(); i++) {
            
            if (intervals[i][0] <= res.back()[1]) {
                // Merge them by updating the end time to the maximum value
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                // No overlap, just add it as a new separate interval
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};
