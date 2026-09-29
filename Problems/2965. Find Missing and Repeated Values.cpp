class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n * n;

        vector<int> freq(total + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                freq[grid[i][j]]++;
            }
        }

        int miss = -1;
        int dupe = -1;

        for (int i = 1; i <= total; i++) {
            if (freq[i] == 0) {
                miss = i;
            } else if (freq[i] == 2) {
                dupe = i;
            }

            // Early exit once both values are identified
            if (miss != -1 && dupe != -1) {
                break;
            }
        }

        return {dupe, miss};
    }
};
