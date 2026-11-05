class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int distance_val = 0;
        
        for (int x : arr1) {
            // Find the first element in arr2 that is >= x - d
            auto it = lower_bound(arr2.begin(), arr2.end(), x - d);
            
            // If no such element exists or the found element is > x + d
            if (it == arr2.end() || *it > x + d) {
                distance_val++;
            }
        }
        
        return distance_val;
    }
};
