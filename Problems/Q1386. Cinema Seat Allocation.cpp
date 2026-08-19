class Solution {
    int helper(unordered_map<int, vector<int>>& mp, int n) {
        int count = (n - mp.size()) * 2;

        for (auto& it : mp) {
            vector<int> row = it.second;

            bool left = true;   // seats 2, 3, 4, 5
            bool right = true;  // seats 6, 7, 8, 9
            bool mid = true;    // seats 4, 5, 6, 7

            for (int seat : row) {
                if (seat >= 2 && seat <= 5) left = false;
                if (seat >= 6 && seat <= 9) right = false;
                if (seat >= 4 && seat <= 7) mid = false;
            }

            if (left && right) {
                count += 2;
            } else if (left || right || mid) {
                count += 1;
            }
        }

        return count;
    }

public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < reservedSeats.size(); i++) {
            int row = reservedSeats[i][0];
            int col = reservedSeats[i][1];

            // Only seats 2 to 9 affect any 4-person family
            if (col >= 2 && col <= 9) {
                mp[row].push_back(col);
            }
        }

        return helper(mp, n);
    }
};
