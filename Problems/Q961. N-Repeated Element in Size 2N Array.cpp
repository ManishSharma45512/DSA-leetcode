class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n= nums.size()/2;
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        for(const auto& p: freq){
            if(p.second==n) return p.first;
        }


        return -1;
    }
};
