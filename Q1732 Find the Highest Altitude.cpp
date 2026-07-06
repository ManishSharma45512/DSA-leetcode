class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        if(gain.size()==0) return 0;

        vector<int> res(gain.size()+1,0);

        for(int i=0;i<gain.size();i++){
            res[i+1]=gain[i]+res[i];

        }

        int max_val = *max_element(res.begin(), res.end());

        return max_val;

        
    }
};
