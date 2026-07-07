class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        if (nums.size() <= 1) return 0; // Base Case

        int count = 0;
        int n = nums.size(); // Track current functional size of the vector

        while (true) {
            // Check if the array is already sorted
            bool isSorted = true;
            for (int i = 0; i < n - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    isSorted = false;
                    break;
                }
            }
            
            // If it is sorted, we are done!
            if (isSorted) break;

            // Scan to find the adjacent pair with the minimum sum
            int minSum = INT_MAX;
            int minIndex = 0;
            
            for (int i = 0; i < n - 1; i++) {
                int currentSum = nums[i] + nums[i + 1];
                if (currentSum < minSum) {
                    minSum = currentSum;
                    minIndex = i;
                }
            }

            
            nums[minIndex] = minSum;

            // Manually shift all elements after the pair to the left to shrink the array size
            for (int i = minIndex + 1; i < n - 1; i++) {
                nums[i] = nums[i + 1];
            }

            count++; // Successfully merged a pair
            n--;     // Shrink the boundary length manually by 1
        }

        return count;
    }
};
