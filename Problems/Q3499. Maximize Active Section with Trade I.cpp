class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int totalOnes = 0;
        
        // Count initial '1's
        for (char c : s) {
            if (c == '1') totalOnes++;
        }

        int maxOnes = totalOnes; // Base case: no trade performed

        // Step 1: Collect lengths of all '0' and '1' blocks in augmented string t = '1' + s + '1'
        // We track consecutive segments: (char_type, length)
        vector<pair<char, int>> blocks;
        string t = '1' + s + '1';

        for (int i = 0; i < t.length(); ) {
            int j = i;
            while (j < t.length() && t[j] == t[i]) {
                j++;
            }
            blocks.push_back({t[i], j - i});
            i = j;
        }

        // Step 2: Look for a '1' block surrounded by '0' blocks
        // In the blocks vector, this looks like: blocks[k-1] = '0', blocks[k] = '1', blocks[k+1] = '0'
        for (int k = 1; k < (int)blocks.size() - 1; k++) {
            if (blocks[k].first == '1' && blocks[k - 1].first == '0' && blocks[k + 1].first == '0') {
                int z1 = blocks[k - 1].second; // left '0' block length
                int z2 = blocks[k + 1].second; // right '0' block length

                // Trading this '1' block gives a net gain of z1 + z2
                maxOnes = max(maxOnes, totalOnes + z1 + z2);
            }
        }

        return maxOnes;
    }
};
