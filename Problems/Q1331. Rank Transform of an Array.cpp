class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        unordered_map<int, int> rankMap;
        int currentRank = 1;

        for (int num : temp) {
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = currentRank;
                currentRank++;
            }
        }

        vector<int> result;
        for (int num : arr) {
            result.push_back(rankMap[num]);
        }

        return result;
    }
};
