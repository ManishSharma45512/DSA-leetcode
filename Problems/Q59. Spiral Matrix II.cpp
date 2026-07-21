class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        bool moveRight = true; // initially move to right
        bool moveDown = false;
        bool moveUp = false;
        bool moveLeft = false;
        
        int i = 0;
        int j = 0;
        int c = 1; // element

        while (c <= n * n) {
            
            if (moveRight) {
                while (j < n && ans[i][j] == 0) {
                    ans[i][j] = c++;
                    j++;
                }
                j--; 
                i++; 
                moveRight = false;
                moveDown = true;
            }

            else if (moveDown) {
                while (i < n && ans[i][j] == 0) {
                    ans[i][j] = c++;
                    i++;
                }
                i--; 
                j--; 
                moveDown = false;
                moveLeft = true;
            }

            else if (moveLeft) {
                while (j >= 0 && ans[i][j] == 0) {
                    ans[i][j] = c++;
                    j--;
                }
                j++; 
                i--; 
                moveLeft = false;
                moveUp = true;
            }

            else if (moveUp) {
                while (i >= 0 && ans[i][j] == 0) {
                    ans[i][j] = c++;
                    i--;
                }
                i++; 
                j++; 
                moveUp = false;
                moveRight = true;
            }
        }

        return ans;
    }
};
