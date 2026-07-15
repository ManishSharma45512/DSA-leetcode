class Solution {
public:
    bool canCross(vector<int>& stones) {
        //base cases
        if (stones.size() == 0 || stones.size() == 1) return true;
        if (stones[1] - stones[0] != 1) return false;

        int n = stones.size();

        stack<pair<int, int>> st;
        st.push({1, 1}); // Start at index 1 with k = 1

   
        unordered_set<int> visited;//to avoided repeating

        while (!st.empty()) {
            auto [i, k] = st.top();
            st.pop();

            if (i == n - 1) return true;// If we reached the last stone, we succeeded!

            int stateKey = i * 2000 + k;
            if (visited.count(stateKey)) continue;
            visited.insert(stateKey);

            for (int j = 1; i + j < n; j++) {
                int gap = stones[i + j] - stones[i];

                if (gap > k + 1) break; //too big

                if (gap == k - 1 || gap == k || gap == k + 1) {
                    st.push({i + j, gap});
                }
            }
        }

        return false;
    }
};
