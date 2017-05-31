// https://leetcode.com/problems/number-of-digit-one/#/description
class Solution {
public:
    int countDigitOne(int n) {
        int ones = 0;
        for (long long m = 1; m <= n; m *= 10) {
            int a = n/m, b = n%m;
            // ones += (a/10 + (a % 10 >= 2? 1 : 0)) * m + a % 10 == 1 ? b+1 : 0;
            ones += (a + 8) / 10 * m + (a % 10 == 1) * (b + 1);
        }
        return ones;
    }
};
