class Solution {
    int sumi(vector<int>& nums,int l,int r){
        int ans=0;
        for(int i=l;i<r;i++){
            ans+=nums[i];
        }

        return ans;
    }

public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mini=INT_MAX;

        for(int size=l;size<=r;size++){
            for(int i=0;i<=nums.size()-size;i++){
                int temp=sumi(nums,i,i+size);
                if(temp<mini && temp>0){
                    mini=temp;
                }
            }
        }

        if(mini==INT_MAX){
            return -1;
        }
        else return mini;
    }
};
