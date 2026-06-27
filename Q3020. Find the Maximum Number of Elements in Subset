class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        unordered_map<int, int> count;//for O(1) counting
        for (int num : nums) {
            count[num]++;
        }

        int maxLen = 1;

        
        if (count.count(1)) {
            int ones = count[1];
            if (ones % 2 == 0) {
                ones--; 
            }
            maxLen = max(maxLen, ones);
        }

        
        for (auto& pair : count) {
            int x = pair.first;
            if (x == 1) continue;

            int currLen = 0;
            long long curr = x; /

            // Loop checks if the base can be duplicated on both left and right sides
            while (curr <= 1000000000 && count.count(curr) && count[curr] >= 2) {
                currLen += 2;
                curr = curr * curr; // Moving up the square ladder (x -> x^2 -> x^4)
            }

            // Checking for the center top element (Peak)
            if (curr <= 1000000000 && count.count(curr) && count[curr] > 0) {
                currLen++; // Perfect peak element found!
            } else {
                currLen--; // Peak missing, boundary pattern chain broken, shrink by 1
            }

            maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }
};
