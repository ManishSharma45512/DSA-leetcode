class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        vector<int> res;
        while (k > 0) {
            int maxfreq = 0;
            int maxVal = INT_MIN;

            for (const auto& p : freq) {
                if (p.second > maxfreq) {
                    maxfreq = p.second;
                    maxVal = p.first;
                }
            }

            res.push_back(maxVal);
            freq[maxVal] = 0;// Mark as processed
            k--;
        }

        return res;
    }
};
