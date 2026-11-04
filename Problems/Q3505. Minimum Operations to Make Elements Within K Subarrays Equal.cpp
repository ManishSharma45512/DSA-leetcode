class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        
        // Step 1: Precompute the minimum operations for every window of size x using two multisets
        vector<long long> minOps;
        multiset<int> lower, upper;
        long long lowerSum = 0, upperSum = 0;
        
        for (int i = 0; i < n; ++i) {
            if (lower.empty() || nums[i] <= *lower.rbegin()) {
                lower.insert(nums[i]);
                lowerSum += nums[i];
            } else {
                upper.insert(nums[i]);
                upperSum += nums[i];
            }
            
            if (i >= x) {
                int outNum = nums[i - x];
                auto it = lower.find(outNum);
                if (it != lower.end()) {
                    lower.erase(it);
                    lowerSum -= outNum;
                } else {
                    upper.erase(upper.find(outNum));
                    upperSum -= outNum;
                }
            }
            
            // Balance the multisets so that |lower| >= |upper| and difference <= 1
            if (lower.size() < upper.size()) {
                int val = *upper.begin();
                upper.erase(upper.begin());
                lower.insert(val);
                upperSum -= val;
                lowerSum += val;
            } else if (lower.size() - upper.size() > 1) {
                int val = *lower.rbegin();
                lower.erase(prev(lower.end()));
                upper.insert(val);
                lowerSum -= val;
                upperSum += val;
            }
            
            if (i >= x - 1) {
                long long median = *lower.rbegin();
                long long ops = (median * lower.size() - lowerSum) + (upperSum - median * upper.size());
                minOps.push_back(ops);
            }
        }
        
        // Step 2: Correct DP to find the minimum total cost of picking k non-overlapping windows
        int m = minOps.size();
        const long long INF = 1e18;
        
        // dp[i][j] represents the minimum cost using j windows from the first i window starting positions
        vector<vector<long long>> dp(m + 1, vector<long long>(k + 1, INF));
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 0;
        }
        
        for (int j = 1; j <= k; ++j) {
            for (int i = 1; i <= m; ++i) {
                // Option 1: Do not include the current window i
                dp[i][j] = dp[i - 1][j];
                
                // Option 2: Include the current window i (starting at index i-1)
                // The previous window must end at or before index i - 1 - x, 
                // which corresponds to considering up to max(0, i - x) starting positions.
                int prev_idx = max(0, i - x);
                if (dp[prev_idx][j - 1] != INF) {
                    dp[i][j] = min(dp[i][j], dp[prev_idx][j - 1] + minOps[i - 1]);
                }
            }
        }
        
        return dp[m][k];
    }
};
