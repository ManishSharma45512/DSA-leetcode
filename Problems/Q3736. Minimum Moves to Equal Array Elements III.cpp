class Solution {
public:
    int minMoves(vector<int>& nums) {
        // Find the minimum element in the array
        int min_val = nums[0];
        int moves = 0;
        
        for (int num : nums) {
            if (num < min_val) {
                min_val = num;
            }
        }
        
        // Accumulate the difference from the minimum element
        for (int num : nums) {
            moves += num - min_val;
        }
        
        return moves;
    }
};
