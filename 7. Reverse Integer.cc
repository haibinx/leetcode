https://leetcode.com/problems/reverse-integer/#/description
class Solution {
public:
    int reverse(int x) {
        bool sign = x < 0;
        long r = labs(x);
        long ans = 0;
        while (r) {
            ans = ans * 10 + r % 10;
            r = r / 10;
        }
        ans = (sign ? -1 : 1) * ans;
        if (ans > INT_MAX || ans < INT_MIN) return 0;
        return ans;
    }
};
