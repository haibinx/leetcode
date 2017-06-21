// https://leetcode.com/problems/add-digits/#/description
class Solution {
public:
    int addDigits(int num) {
        while(num >= 10) {
            int n = num;
            num = 0;
            while(n > 0) {
                num += n % 10;
                n /= 10;
            }
        }
        return num;
    }
    
    int addDigits(int num) {
        if (num < 10) return num;
        int m = num % 9;
        return m == 0 ? 9 : m;
    }
};
