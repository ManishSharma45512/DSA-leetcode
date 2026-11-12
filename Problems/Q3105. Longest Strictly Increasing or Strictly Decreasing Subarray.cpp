class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi=0;

        for(int i=0;i<nums.size();i++){
            int j=i;
            int temp=0;
            while(j<nums.size()-1 && nums[j+1]>nums[j]){
                j++;
                temp++;
            }

            if(temp>maxi){
                maxi=temp;
            }

        }

        for(int i=0;i<nums.size();i++){
            int j=i;
            int temp=0;
            while(j<nums.size()-1 && nums[j+1]<nums[j]){
                j++;
                temp++;
            }

            if(temp>maxi){
                maxi=temp;
            }

        }

        return maxi+1;

    }
};
