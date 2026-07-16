class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 0) return 0; // Base Case
        if(points.size() == 1) return 1; // Safeguard if there's only 1 point

        int maxpoint = 1; // Initialize to 1 since at least 1 point is always on a line

        for(int i = 0; i < points.size(); i++) { // [x1,y1]
            unordered_map<double, vector<vector<int>>> slope; 

            for(int j = 0; j < points.size(); j++) { // [x2,y2]
                if(i == j) continue;

                long long deltay = points[j][1] - points[i][1]; // y2-y1
                long long deltax = points[j][0] - points[i][0]; // x2-x1

                double tempslope = (double)deltay / deltax; 


                if(slope[tempslope].empty()) {
                    slope[tempslope].push_back(points[i]);
                }
                slope[tempslope].push_back(points[j]);
            }
            
            
            for(auto pair : slope) {
                if(pair.second.size() >= 2) {//It is a line
                    int n = pair.second.size();
                    if(n > maxpoint) {
                        maxpoint = n; 
                    }
                }
            }
        }

        return maxpoint;
    }
};
