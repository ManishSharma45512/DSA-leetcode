class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        
        // STAGE 1: Setup boundaries
        // Building 1 always has a fixed height of 0. We treat this as a starting restriction.
        restrictions.push_back({1, 0});
        
        // Sort all restrictions by their Building ID (from lowest ID to highest ID)
        sort(restrictions.begin(), restrictions.end());
        
        // If the very last building (n) doesn't have a rule, we add a theoretical maximum restriction.
        // Since it's 'n' steps away from building 1, its absolute maximum possible height is n - 1.
        if (restrictions.back()[0] != n) {
            restrictions.push_back({n, n - 1});
        }
        
        int totalRestrictions = restrictions.size();
        
        // STAGE 2: Left-to-Right Pass (Push limits forward)
        // Ensure no building is taller than its left neighbor + the distance between them.
        for (int i = 1; i < totalRestrictions; ++i) {
            int leftId     = restrictions[i - 1][0];
            int leftHeight = restrictions[i - 1][1];
            
            int currentId     = restrictions[i][0];
            int currentHeight = restrictions[i][1];
            
            int distance = currentId - leftId;
            int maxAllowedFromLeft = leftHeight + distance;
            
            // Update the current building's height limit to the stricter option
            restrictions[i][1] = min(currentHeight, maxAllowedFromLeft);
        }
        
        // STAGE 3: Right-to-Left Pass (Push limits backward)
        // Ensure no building is taller than its right neighbor + the distance between them.
        for (int i = totalRestrictions - 2; i >= 0; --i) {
            int rightId     = restrictions[i + 1][0];
            int rightHeight = restrictions[i + 1][1];
            
            int currentId     = restrictions[i][0];
            int currentHeight = restrictions[i][1];
            
            int distance = rightId - currentId;
            int maxAllowedFromRight = rightHeight + distance;
            
            // Update the current building's height limit to the stricter option
            restrictions[i][1] = min(currentHeight, maxAllowedFromRight);
        }
        
        // STAGE 4: Calculate the highest peak between any two restricted buildings
        int absoluteMaxHeight = 0;
        
        for (int i = 0; i < totalRestrictions - 1; ++i) {
            int id1 = restrictions[i][0];
            int h1  = restrictions[i][1];
            
            int id2 = restrictions[i + 1][0];
            int h2  = restrictions[i + 1][1];
            
            int distance = id2 - id1;
            
            // Formula to find the tallest peak possible between two points:
            // They both build up towards each other until they meet.
            int peakBetweenThem = (h1 + h2 + distance) / 2;
            
            // Keep track of the tallest peak we've seen so far
            absoluteMaxHeight = max(absoluteMaxHeight, peakBetweenThem);
        }
        
        return absoluteMaxHeight;
    }
};
