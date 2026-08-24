//Math approch
// Place-by-place counting trick (Units, Tens, Hundreds, ... where m = 1, 10, 100, ...):
// Split n into higher part a = n / (m*10), current digit b = (n/m) % 10, and lower part c = n % m.
// 1) If b == 0: count += a * m
// 2) If b == 1: count += a * m + (c + 1)
// 3) If b  > 1: count += (a + 1) * m
// Example n = 314: m=1 -> (31+1)*1=32
//                  m=10 -> 3*10+(4+1)=35
//                  m=100 -> (0+1)*100=100 => Total = 167


class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0;

        for (long long m = 1; m <= n; m *= 10) {
            long long a = n / (m * 10);
            long long b = (n / m) % 10;
            long long c = n % m;

            if (b == 0) {
                count += a * m;
            } else if (b == 1) {
                count += a * m + (c + 1);
            } else {
                count += (a + 1) * m;
            }
        }

        return count;
    }
};
