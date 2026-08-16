class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int count[3] = {0, 0, 0};
        for (int x : stones) {
            count[x % 3]++;
        }

        int c0 = count[0];
        int c1 = count[1];
        int c2 = count[2];

        // If c0 is even, Alice needs at least one '1' and at least one '2'
        if (c0 % 2 == 0) {
            return c1 >= 1 && c2 >= 1;
        }

        // If c0 is odd, Alice needs the difference between c1 and c2 to be greater than 2
        return abs(c1 - c2) > 2;
    }
};
