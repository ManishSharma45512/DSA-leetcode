/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 * int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> solutions;
        
        int x = 1;
        int y = 1000;
        
        while (x <= 1000 && y >= 1) {
            int val = customfunction.f(x, y); 
            
            if (val == z) {
                solutions.push_back({x, y});
                x++; // Move right to look for other pairs
                y--; // Move down to look for other pairs
            } 
            else if (val < z) {
                // Value is too small, we need a larger f(x,y). 
                // Since y is decreasing, our only option to increase val is to increase x.
                x++;
            } 
            else {
                // Value is too large, we need a smaller f(x,y).
                // Since x is increasing, our only option to decrease val is to decrease y.
                y--;
            }
        }
        
        return solutions;
    }
};
