// https://leetcode.com/problems/fraction-to-recurring-decimal/#/description
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) return "0";
        string ans = "";
        if (numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0 ) {
            ans += '-';
        }
        long n = abs((long)numerator);
        long d = abs((long)denominator);
        ans += to_string(n / d);
        long r = n % d;
        if (r == 0) return ans;
        ans += ".";
        unordered_map<int, int> mp;
        while (r != 0) {
            if (mp.find(r) == mp.end()) {
                mp[r] = ans.size();
                long t = r * 10 / d;
                r = r * 10 % d;
                ans += to_string(t);
            } else {
                int pos = mp[r];
                ans.insert(pos, "(");
                ans.push_back(')');
                break;
            }
        }
        return ans;
    }
};
