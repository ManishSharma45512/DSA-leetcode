class Solution {
public:
    vector<int> getRow(int n) {
        
        vector<vector<int>> res;

        
        for (int i = 0; i <= n; i++) { 
            vector<int> row;
            
            for (int j = 0; j <= i; j++) { 
                if (j == 0 || j == i) {
                    row.push_back(1);
                } 
                else {
                    row.push_back(res[i-1][j-1] + res[i-1][j]);
                }
            }
            res.push_back(row);
        }

        return res[n]; 
    }
};
