class Solution {
    int minNeeded(int r2, int r3, int r5, int r7) {
        int count = r5 + r7;
        int c9 = r3 / 2; r3 %= 2;
        int c8 = r2 / 3; r2 %= 3;

        int extra = 0;
        if (r2 == 2 && r3 == 1) extra = 2;
        else if (r2 == 2 || r3 == 1 || r2 == 1) extra = 1;

        return count + c9 + c8 + extra;
    }

    void updateFactors(int d, int& r2, int& r3, int& r5, int& r7, int mult) {
        if (d == 2) r2 += mult;
        else if (d == 3) r3 += mult;
        else if (d == 4) r2 += 2 * mult;
        else if (d == 5) r5 += mult;
        else if (d == 6) { r2 += mult; r3 += mult; }
        else if (d == 7) r7 += mult;
        else if (d == 8) r2 += 3 * mult;
        else if (d == 9) r3 += 2 * mult;
    }

    string buildSuffix(int len, int r2, int r3, int r5, int r7) {
        string suf = "";
        for (int i = 0; i < len; i++) {
            int remLen = len - 1 - i;
            for (int d = 1; d <= 9; d++) {
                int nr2 = r2, nr3 = r3, nr5 = r5, nr7 = r7;
                updateFactors(d, nr2, nr3, nr5, nr7, -1);

                if (minNeeded(max(0, nr2), max(0, nr3), max(0, nr5), max(0, nr7)) <= remLen) {
                    suf += to_string(d);
                    r2 = nr2; r3 = nr3; r5 = nr5; r7 = nr7;
                    break;
                }
            }
        }
        return suf;
    }

public:
    string smallestNumber(string num, long long t) {
        int r2 = 0, r3 = 0, r5 = 0, r7 = 0;
        while (t % 2 == 0) { r2++; t /= 2; }
        while (t % 3 == 0) { r3++; t /= 3; }
        while (t % 5 == 0) { r5++; t /= 5; }
        while (t % 7 == 0) { r7++; t /= 7; }

        if (t > 1) return "-1";

        int n = num.length();
        int firstZero = num.find('0');

        // Check if num itself is valid FIRST before touching any prefix factors
        if (firstZero == string::npos) {
            int tr2 = r2, tr3 = r3, tr5 = r5, tr7 = r7;
            for (char c : num) {
                updateFactors(c - '0', tr2, tr3, tr5, tr7, -1);
            }
            if (minNeeded(max(0, tr2), max(0, tr3), max(0, tr5), max(0, tr7)) == 0) {
                return num;
            }
        }

        int limit = (firstZero != string::npos) ? firstZero : n - 1;

        // Calculate factors of prefix up to index (limit - 1)
        int pr2 = r2, pr3 = r3, pr5 = r5, pr7 = r7;
        for (int i = 0; i < limit; i++) {
            updateFactors(num[i] - '0', pr2, pr3, pr5, pr7, -1);
        }

        // Backtrack from limit down to 0
        for (int i = limit; i >= 0; i--) {
            int curD = num[i] - '0';
            for (int d = curD + 1; d <= 9; d++) {
                int nr2 = pr2, nr3 = pr3, nr5 = pr5, nr7 = pr7;
                updateFactors(d, nr2, nr3, nr5, nr7, -1);

                int remLen = n - 1 - i;
                if (minNeeded(max(0, nr2), max(0, nr3), max(0, nr5), max(0, nr7)) <= remLen) {
                    string res = num.substr(0, i) + to_string(d);
                    res += buildSuffix(remLen, nr2, nr3, nr5, nr7);
                    return res;
                }
            }
            if (i > 0) {
                updateFactors(num[i - 1] - '0', pr2, pr3, pr5, pr7, 1);
            }
        }

        // Increase string length if prefix match is impossible
        int targetLen = max((int)n + 1, minNeeded(max(0, r2), max(0, r3), max(0, r5), max(0, r7)));
        return buildSuffix(targetLen, r2, r3, r5, r7);
    }
};
