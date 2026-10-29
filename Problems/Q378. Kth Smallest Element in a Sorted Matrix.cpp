class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        int ans = low;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (countLessEqual(matrix, mid) >= k) {
                ans = mid;
                high = mid - 1; // Try to find a smaller valid value
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

private:
    int countLessEqual(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int count = 0;
        int row = n - 1;
        int col = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] <= target) {
                count += (row + 1);
                col++;
            } else {
                row--;
            }
        }
        return count;
    }
};
