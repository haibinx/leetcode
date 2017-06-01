// https://leetcode.com/problems/basic-calculator/#/description
class Solution {
public:
    int calculate(string s) {
        int res = 0, sign = 1, n = s.length();
        int num = 0;
        stack<pair<int,int>> st;
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
            } else if (s[i] == '+' || s[i] == '-') {
                res += sign * num;
                num = 0;
                sign = (s[i] == '+') ? 1 : -1;
            } else if (s[i] == '(') {
                st.push(make_pair(sign, res));
                res = 0;
                sign = 1;
            } else if (s[i] == ')') {
                res += sign * num;
                num = 0;
                res = st.top().second + st.top().first * res;
                st.pop();
            }
        }
        res += sign * num;
        return res;
    }
};
