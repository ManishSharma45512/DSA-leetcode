class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even_chips = 0;
        int odd_chips = 0;

        // Loop through all chips to see if their coordinate is even or odd
        for(int i = 0; i < position.size(); i++) { // O(n)
            if (position[i] % 2 == 0) {
                even_chips++; // moving between even positions costs 0
            } else {
                odd_chips++;  // moving between odd positions costs 0
            }
        }

        // final cost=min*1 becoz we need odd move 
        return min(even_chips, odd_chips);
    }
};
