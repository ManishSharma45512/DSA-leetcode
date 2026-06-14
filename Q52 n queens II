class Solution {
private:
    int count = 0;
    
    // Fast boolean arrays to track lines of attack
    vector<bool> cols, d1, d2;

    void backtrack(int r, int n) {
        // Base case: If we successfully reached the past-the-end row
        if (r == n) {
            count++;
            return;
        }

        for (int c = 0; c < n; ++c) {
            // Check if the column or either diagonal is blocked
            if (cols[c] || d1[r + c] || d2[r - c + n]) {
                continue; 
            }

            // 1. Place Queen
            cols[c] = d1[r + c] = d2[r - c + n] = true;

            // 2. Move to next row
            backtrack(r + 1, n);

            // 3. Remove Queen (Backtrack)
            cols[c] = d1[r + c] = d2[r - c + n] = false;
        }
    }

public:
    int totalNQueens(int n) {
        count = 0;
        
        // Allocate space for the tracking arrays
        cols.assign(n, false);
        d1.assign(2 * n, false);
        d2.assign(2 * n, false);

        // Start the recursion at Row 0
        backtrack(0, n);
        
        return count;
    }
};
