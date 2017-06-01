// https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/#/description
class Solution {
public:
    int findIntegers(int num) {
        int n = 0;
        int temp = num;
        while(temp > 0) {
            temp >>= 1;
            n++;
        }
        vector<int> a(n, 1);
        vector<int> b(n, 1);
        for (int i = 1; i < n; i++) {
            a[i] = a[i - 1] + b[i - 1];
            b[i] = a[i - 1];
        }
        int res = a[n-1] + b[n-1];
        for (int i = n -2; i >=0; --i) {
            if (((num >> i) & 1) && ((num >> i+1) & 1)) break;
            if (!((num >> i) & 1) && !((num >> i+1) & 1))  res -= b[i];
        }
        return res;
    }
};
