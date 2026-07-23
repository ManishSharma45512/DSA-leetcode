class Solution {
    string intToBinary(int num) {
        if (num == 0) return "0";

        string s = bitset<32>(num).to_string();
        
        return s.substr(s.find_first_not_of('0'));
    }

    int countOne(string nums) {
        int c = 0;
        for (int i = 0; i < nums.length(); i++) {
            if (nums[i] == '1') c++;
        }

        return c;
    }

public:
    vector<int> countBits(int n) {
        vector<int> nums;
        for (int i = 0; i <= n; i++) {
            nums.push_back(countOne(intToBinary(i)));
        }

        return nums;
    }
};
