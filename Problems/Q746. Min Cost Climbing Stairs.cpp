class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()==0) return 0;//Base case

        //Tabulation starts from here
        int n=cost.size();
        vector<int> dp(n+1,0); // this includes our dp[0]=dp[1]=0  :: Initialization
        for(int i=2;i<=n;i++){
            dp[i]=min(cost[i-1]+dp[i-1],cost[i-2]+dp[i-2]);
        }

        return dp[n];
    }
};
