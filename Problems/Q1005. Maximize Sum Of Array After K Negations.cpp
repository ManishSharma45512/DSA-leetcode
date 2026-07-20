class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        if(nums.size() == 0) return 0; //Base Case

        // We will be using greedy here
        // sort once upfront to bring the lowest/most-negative numbers to the front
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() && k > 0; i++) {
            if (nums[i] < 0) {// Flip the negative numbers
                nums[i] = -nums[i];
                k--;
            }
        }

        // if k is still odd, find the absolute lowest number now and flip it once
        if (k % 2 == 1) {
            sort(nums.begin(), nums.end()); // one final quick sort to find the new minimum
            nums[0] = -nums[0];
        }


        //no need to do anything if even then nothing will change eg. k=2 nums[0]=1->-1->1

        
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) { // O(n)
            sum += nums[i];
        }

        return sum;
    }
};
