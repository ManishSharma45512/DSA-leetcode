class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;

        vector<bool> out(intervals.size(), false);

        for(int i = 0; i < intervals.size(); i++){
            if (out[i] == true) continue;
            
            for(int j = 0; j < intervals.size(); j++){
                if(i == j) continue; // same element

                // If interval j completely covers interval i
                if(intervals[j][0] <= intervals[i][0] && intervals[j][1] >= intervals[i][1]) {
                    out[i] = true; // i is covered, so eliminate i!
                    break;         // i is eliminated, no need to check other j's for it
                }
            }
        }

        int count = 0;
        for(int i = 0; i < out.size(); i++){
            if(out[i] == false) count++;
        }

        return count;
    }
};
