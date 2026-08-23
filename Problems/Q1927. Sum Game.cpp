class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int sumDiff = 0; // S_L - S_R
        int qDiff = 0;   // Q_L - Q_R

        // Left half
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') {
                qDiff++;
            } else {
                sumDiff += (num[i] - '0');
            }
        }

        // Right half
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') {
                qDiff--;
            } else {
                sumDiff -= (num[i] - '0');
            }
        }

        // Alice wins if total '?' difference is odd
        if (qDiff % 2 != 0) {
            return true;
        }

        // Bob wins if the sum imbalance exactly cancels out with Bob's 9-pairing strategy
        // 2 * (S_L - S_R) + 9 * (Q_L - Q_R) == 0
        if (2 * sumDiff + 9 * qDiff == 0) {
            return false;
        }

        return true;
    }
};
