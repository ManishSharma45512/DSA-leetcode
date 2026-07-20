class Solution {
public:
    int abs(int i){
        if(i < 0) return -i; // FIX 1: Check if the number is less than 0, not itself

        return i;
    }
    
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> count;
        for (int num : arr) {//O(n)-tracking count of every element
            count[num]++;
        }


        sort(arr.begin(), arr.end(), [this](int a, int b) {//first check magnitude then add it up eg.[2,2,4,4]->[-2,2,4,-4]
            return abs(a) < abs(b);
        });

        //pair everything up
        for (int num : arr) {
            if (count[num] == 0) continue;

            if (count[num * 2] == 0) return false;//no partner

            //found a pair so Consume one instance of both numbers
            count[num]--;
            count[num * 2]--;
        }

        return true;
    }
};
