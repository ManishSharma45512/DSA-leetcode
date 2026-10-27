class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            grid[0][j]=1;
        }

        for(int i=0;i<m;i++){
            grid[i][n-1]=1;
        }

        vector<string> ans(m,"");
        for(int i=0;i<m;i++){
            string temp="";
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    temp+="#";
                }
                else{
                    temp+=".";
                }
            }

            ans[i]=temp;
        }

        return ans;
    }
};
