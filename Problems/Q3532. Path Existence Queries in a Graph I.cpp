#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mod(int a) {
        if (a < 0) return -a;
        return a;
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> result;
        if (nums.size() == 0) return result;

        // Create a running counter of how many "bad jumps" have occurred up to index i
        vector<int> badJumpsPrefix(n, 0);
        for (int i = 0; i < n - 1; i++) {
            int modVal = mod(nums[i + 1] - nums[i]);
            
            // If this jump is illegal, mark it as 1, otherwise 0
            int isBad = (modVal > maxDiff) ? 1 : 0;
            
            badJumpsPrefix[i + 1] = badJumpsPrefix[i] + isBad;
        }

        for (int i = 0; i < queries.size(); i++) {
            int st = queries[i][0];
            int end = queries[i][1];

            // Normalize boundaries so left is always the smaller index
            int left = min(st, end);
            int right = max(st, end);

            // Instant Check: If the count of bad jumps changes between 'left' and 'right',
            // it means at least one illegal gap exists in that interval!
            bool inMax = (badJumpsPrefix[right] - badJumpsPrefix[left] == 0);

            result.push_back(inMax);
        }

        return result;
    }
};
