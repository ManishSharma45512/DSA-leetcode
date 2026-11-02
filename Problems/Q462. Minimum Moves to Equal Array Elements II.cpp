class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());//O(nlogn)
        int mid=nums.size()/2;

        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<nums[mid]){
                c+=nums[mid]-nums[i];
            }
            else{
                c+=nums[i]-nums[mid];
            }
        }

        return c;
    }
};
