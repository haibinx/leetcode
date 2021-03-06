// https://leetcode.com/problems/divide-two-integers/#/description
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;
        while (dvd >= dvs) {
            long long temp = dvs, t = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                t <<= 1;
            }
            dvd -= temp;
            res += t;
        }
        return sign == 1 ? res : -res; 
    }
};
