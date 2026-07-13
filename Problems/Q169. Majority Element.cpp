class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==0) return 0;//Base Case

        unordered_map<int,int> freq;
        int majElement=0;
        int majFreq=INT_MIN;

        for(int i=0;i<nums.size();i++){//O(n)
            freq[nums[i]]++;
            if(freq[nums[i]]>majFreq){
                majFreq=freq[nums[i]];
                majElement=nums[i];
            }
        }

        return majElement;
    }
};
