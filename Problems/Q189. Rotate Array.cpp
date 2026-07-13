class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 0) return;

        k %= nums.size();
        int n = nums.size();

        deque<int> dq(nums.begin(), nums.end());//dequeue for both side access

        for(int i = 0; i < k; i++) {
            int val = dq.back();
            dq.pop_back();          // Removes last value O(1)
            dq.push_front(val);     // Puts it at the beginning O(1)
        }

        nums.assign(dq.begin(), dq.end());
    }
};
