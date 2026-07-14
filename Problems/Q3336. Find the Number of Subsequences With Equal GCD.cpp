#define ll long long int
#define mod 1000000007

class Solution {
    // Given : max value in nums is <= 200 
    ll dp[201][201][201]; 
public:
    ll solve(int i, vector<int> &nums, int gcd1, int gcd2){
        // Base case: check if both subsequences are non-empty and have matching GCDs
        if(i == nums.size()){
            return (gcd1 > 0 && gcd2 > 0 && gcd1 == gcd2);
        }

        if(dp[i][gcd1][gcd2] != -1){
            return dp[i][gcd1][gcd2];
        }

        // Skip the current element entirely
        ll ans = solve(i + 1, nums, gcd1, gcd2);

        // : Put the element into the first subsequence
        ans = (ans + solve(i + 1, nums, gcd(gcd1, nums[i]), gcd2)) % mod;

        // Put the element into the second subsequence
        ans = (ans + solve(i + 1, nums, gcd1, gcd(gcd2, nums[i]))) % mod;

        return dp[i][gcd1][gcd2] = ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));

        return solve(0, nums, 0, 0); 
    }
};
