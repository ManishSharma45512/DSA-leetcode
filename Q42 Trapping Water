class Solution {
public:
    int binarysum(vector<int>& water, int st, int end, int res) {
        if (st <= end) { 
            int mid = st + (end - st) / 2;
            res = res + water[mid];
            
            res = binarysum(water, st, mid - 1, res);
            res = binarysum(water, mid + 1, end, res);
        }
        return res;
    } 

    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        vector<int> water(height.size(), 0);
        int n = height.size();

        
        int i = 0;
        while (i < n && height[i] == 0) {
            i++;
        }

        
        while (i < n) {
            int j = i + 1;
            int highest_idx = j;
            
            
            while (j < n && height[j] < height[i]) {
                if (highest_idx < n && height[j] > height[highest_idx]) {
                    highest_idx = j;
                }
                j++;
            }

            
            if (j < n) {
                
                for (int k = i + 1; k < j; k++) {
                    water[k] = height[i] - height[k];
                }
                i = j; 
            } else {
                
                if (highest_idx < n) {
                    for (int k = i + 1; k < highest_idx; k++) {
                        water[k] = height[highest_idx] - height[k];
                    }
                    i = highest_idx; // Move left pointer to this local maximum
                } else {
                    i++;
                }
            }
        }

        
        int res = 0;
        return binarysum(water, 0, water.size() - 1, res);
    }
};
