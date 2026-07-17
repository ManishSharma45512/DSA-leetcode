class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int m = *max_element(nums.begin(), nums.end());
        vector<long long> count(m + 1, 0);
        vector<long long> gcd_count(m + 1, 0);

        for(int num : nums) count[num]++; //increase count of number present in the nums

        //counting how many numbers are multiples of i
        for(int i = 1; i <= m; i++){
            for(int j = i; j <= m; j += i){
                gcd_count[i] += count[j];
            }
            //calculating total pairs that share i as a common divisor
            gcd_count[i] = (gcd_count[i] * (gcd_count[i] - 1)) / 2;
        }

        //removing higher multiples to get exact GCD counts
        for(int i = m; i >= 1; i--){
            for(int j = i * 2; j <= m; j += i) {
                gcd_count[i] -= gcd_count[j]; //removing of gcd of more nums like 5 is gcd of 5,10,15,20,...
                                              //but gcd for 10 and 20 is 10 despite being a multiple of 5
            }
        }

        for(int i = 1; i <= m; i++) gcd_count[i] += gcd_count[i - 1]; //making prefixSum for newly refined counts

        vector<int> ans;
        for(long long q : queries){ //answering queries using binary search
            long long target = q + 1;
            int pos = lower_bound(gcd_count.begin(), gcd_count.end(), target) - gcd_count.begin();
            ans.push_back(pos);
        }

        return ans;
    }
};
