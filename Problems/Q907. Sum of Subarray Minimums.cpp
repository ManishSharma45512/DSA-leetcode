class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long MOD = 1e9 + 7;

        vector<int> left(n), right(n);
        stack<pair<int, int>> s1, s2; // {element, count}

        // 1. Distance to Previous Smaller Element (Left)
        for (int i = 0; i < n; i++) {
            int count = 1;
            while (!s1.empty() && s1.top().first > arr[i]) {
                count += s1.top().second;
                s1.pop();
            }
            s1.push({arr[i], count});
            left[i] = count;
        }

        // 2. Distance to Next Smaller Element (Right)
        // Use '>=' to prevent double-counting equal numbers
        for (int i = n - 1; i >= 0; i--) {
            int count = 1;
            while (!s2.empty() && s2.top().first >= arr[i]) {
                count += s2.top().second;
                s2.pop();
            }
            s2.push({arr[i], count});
            right[i] = count;
        }

        // 3. Sum up total contributions
        long long totalSum = 0;
        for (int i = 0; i < n; i++) {
            long long totalSubarrays = (long long)left[i] * right[i];
            totalSum = (totalSum + totalSubarrays % MOD * arr[i]) % MOD;
        }

        return totalSum;
    }
};
