class Solution {
    bool isPrime(int n){
        if(n<2) return false;

        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }

        return true;
    }

    
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int n :  nums){
            freq[n]++;
        }

        for(const auto [num,count] : freq){
            if(isPrime(count)) return true;
        }

        return false;
    }
};
