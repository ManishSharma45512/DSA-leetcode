class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq1;
        unordered_map<int,int> freq2;

        for(int i=0;i<nums1.size();i++){
            freq1[nums1[i]]++;
        }

        for(int i=0;i<nums2.size();i++){
            freq2[nums2[i]]++;
        }

        vector<int> ans;


        //check smallest array

        int n=0;
        vector<int> temp;
        if(nums1.size()<=nums2.size()){
            n=nums1.size();
            temp = nums1;
        } 
        else{
            n=nums2.size();
            temp=nums2;
        }
        

        for(int i=0;i<n;i++){
            int val=temp[i];
            if(freq1[val]>0 && freq2[val]>0){//if already visited then don't need to add agin
                ans.push_back(val);
                freq1[val]--;
                freq2[val]--;
            }
        }

        return ans;


    }
};
