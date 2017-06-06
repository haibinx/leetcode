// https://leetcode.com/problems/powx-n/#/description
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (fabs(x -1) < 1e-7) return 1;
        if (fabs(x) < 1e-7) return 0;
        if (n < 0) {
            if (n == INT_MIN) return 1 / (myPow(x, INT_MAX) * x);
            return 1 / myPow(x, -n);
        }
        double t = myPow(x, n/2);
        if (n & 1) {
            return t*t*x;
        } else {
            return t*t;
        }
    }
};
