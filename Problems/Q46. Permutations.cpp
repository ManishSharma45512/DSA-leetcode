class Solution {
public:
    void getPer(vector<int> &nums,int idx,vector<vector<int>> &ans){

        if(idx==nums.size()){//Base Case
            ans.push_back({nums});
            return;
        
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);//idx place= ith choice
            getPer(nums,idx+1,ans);//Recursive
            swap(nums[idx],nums[i]);//BackTrack to get our original nums back
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPer(nums,0,ans);
        return ans;
    }
};
