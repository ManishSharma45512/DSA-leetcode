class Solution {
    bool isUnique(int num) {
        bool visited[10] = {false};
        
        while (num > 0) {
            int temp = num % 10;
            if (visited[temp]) return false; //Not Unique

            visited[temp] = true;
            num /= 10;
        }

        return true;
    }

public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1; // Base case:

        int upper = 1; // 10^0
        for (int i = 1; i <= n; i++) {
            upper *= 10;
        }

        int c = 1;
        
        for (int i = 1; i < upper; i++) {
            if (isUnique(i)) c++;
        }

        return c;
    }
};
