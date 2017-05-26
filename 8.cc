// https://leetcode.com/problems/string-to-integer-atoi/#/description
class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        int sign = 1;
        const char * s = str.c_str();
        while(*s == ' ') s++;
        if (*s == '-' || *s == '+') {
            if (*s == '-') {
                sign = -1;
            }
            s++;
        }
        while (isdigit(*s)) {
            result = result * 10 + (*s - '0');
            if(result*sign >= INT_MAX) return INT_MAX;
            if(result*sign <= INT_MIN) return INT_MIN;
            s++;
        }
        return result * sign;
    }
};
