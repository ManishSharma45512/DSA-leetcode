class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size()-1;//pre set for number of elements increment to +1
        int c=0;
        //finding min
        int min=INT_MAX;

        for(int i=0;i<=n;i++){
            if(nums[i]<min){
                min=nums[i];
            }
        }

        for(int i=0;i<=n;i++){
            c+=nums[i]-min;
        }

        return c;
    }
};
