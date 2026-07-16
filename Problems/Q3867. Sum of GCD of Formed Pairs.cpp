class Solution {
    
public:
    

    long long gcdSum(vector<int>& nums) {
        
        int n=nums.size();
        int prefixMax=0;
        if(n==0) return 0;

        vector<int> prefixGCD(n);
        for(int i=0;i<n;i++){//O(n)
            prefixMax=max(prefixMax,nums[i]);
            prefixGCD[i]=gcd(nums[i],prefixMax);
        }


        sort(prefixGCD.begin(),prefixGCD.end());//O(nlogn) sorting

        int left=0;
        int right=n-1;
        long long sum=0;

        while(left < right){
            sum+=gcd(prefixGCD[left],prefixGCD[right]);
            left++;
            right--;
        }

        return sum;
    }
};
