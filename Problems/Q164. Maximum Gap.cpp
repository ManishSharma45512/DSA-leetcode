class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()==1) return 0;//Base Case
        sort(nums.begin(),nums.end());
        
        int maxG=0;
        for(int i=0;i<nums.size()-1;i++){
            int diff=nums[i+1]-nums[i];
            maxG=max(maxG,diff);
        }

        return maxG;
    }
};
