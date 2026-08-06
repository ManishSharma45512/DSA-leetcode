class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st(arr.begin(), arr.end());
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = arr[i];
                int b = arr[j];
                int len = 2;

                while (st.count(a + b)) {
                    int temp = a + b;
                    a = b;
                    b = temp;
                    len++;
                }

                if (len >= 3) {
                    maxLen = max(maxLen, len);
                }
            }
        }

        return maxLen;
    }
};
