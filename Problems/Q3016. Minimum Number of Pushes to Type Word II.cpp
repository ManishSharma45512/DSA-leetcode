class Solution {
public:
    int minimumPushes(string word) {
        // Step 1: Count frequency of each character
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }

        // Step 2: Sort frequencies in descending order
        sort(freq.rbegin(), freq.rend());

        int totalPushes = 0;

        // Step 3: Greedy calculation
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break; // Stop early if no more characters remain

            int pushCost = (i / 8) + 1; // 1 push for first 8, 2 for next 8, etc.
            totalPushes += freq[i] * pushCost;
        }

        return totalPushes;
    }
};
