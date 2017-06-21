// https://leetcode.com/problems/complex-number-multiplication/#/description
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        istringstream ia(a);
        istringstream ib(b);
        int aa, ab, ba, bb;
        char op;
        ia >> aa >> op >> ab;
        ib >> ba >> op >> bb;
        int ca = aa * ba - ab * bb;
        int cb = aa * bb + ab * ba;
        return to_string(ca) + "+" + to_string(cb) + "i";
    }
};
