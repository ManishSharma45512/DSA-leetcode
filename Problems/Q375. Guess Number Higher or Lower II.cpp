class Solution {
    int helper(int st,int end,vector<vector<int>>& dp){
        if(st>=end) return 0;//Base Case

        if(dp[st][end]!=-1) return dp[st][end];//already checked

        int min_cost=INT_MAX;
        for(int x=st;x<=end;x++){
            int worst=x+max(helper(x+1,end,dp),helper(st,x-1,dp));
            min_cost=min(min_cost,worst);
            
        }


        return dp[st][end]=min_cost;//point is checked and is alloted its minimum value
    }

public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return helper(1,n,dp);
        
    }
};
