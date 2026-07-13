class Solution {
public:
    int robHelper(vector<int>& nums,int start,int end){
        if(start==end) return nums[start];

        int n= end-start+1;

        vector<int> dp(n,0);

        dp[0]=nums[start];
        dp[1]=max(nums[start],nums[start+1]);

        for(int i=2;i<n;i++){
            int curr=start+i;

            dp[i] = max(dp[i-1],nums[curr]+dp[i-2]);

        }

        return dp[n-1];
    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0],nums[1]);
        

        int firstToSecondLast = robHelper(nums,0,n-2);

        int secondToLast = robHelper(nums,1,n-1);

        return max(firstToSecondLast,secondToLast);


        
    }
};
