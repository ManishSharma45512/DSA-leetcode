class Solution {
public:
    int maxJump(vector<int>& stones) {
        // Base case:
        if (stones.size() == 2) {
            return stones[1] - stones[0];
        }
        
        int max_jump = 0;
        
        // Check the maximum jump if we alternate (skip one stone every time)
        for (int i = 2; i < stones.size(); i++) {
            max_jump = max(max_jump, stones[i] - stones[i - 2]);
        }
        
        return max_jump;
    }
};
