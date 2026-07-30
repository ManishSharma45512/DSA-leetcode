class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        
        map<int, vector<int>> diffMap;
        for (int i = 0; i < n; i++) {
            diffMap[abs(arr[i] - x)].push_back(arr[i]);
        }

        vector<int> res;
        for (auto& pair : diffMap) {
            for (int val : pair.second) {
                if (k > 0) {
                    res.push_back(val);
                    k--;
                } else {
                    break;
                }
            }
            if (k == 0) break;
        }

        sort(res.begin(), res.end());
        return res;
    }
};
