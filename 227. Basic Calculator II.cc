// https://leetcode.com/problems/basic-calculator-ii/#/description
class Solution {
public:
    int calculate(string ss) {
        istringstream in("+" + ss + "+");
        char op;
        int total = 0, preVal = 0, n;
        while(in >> op) {
            if(op == '+' || op == '-') {
                total += preVal;
                in >> preVal;
                preVal *= (op == '+') ? 1 : -1;
            } else if(op == '*') {
                in >> n;
                preVal *= n;
            } else if(op == '/') {
                in >> n;
                preVal /= n;
            }
        }
        return total;
    }
    
    // Solution 2
    int calculate2(string ss) {
        int total = 0, preVal = 0;
        string s = "+" + ss + "+";
        for(int i = 0; i < s.size(); i++) {
            if(isspace(s[i])) continue;
            char op = s[i];
            if(op == '+' || op == '-') {
                total += preVal;
                preVal = parse(s, ++i);
                preVal *= (op == '+') ? 1 : -1;
            }
            else if(op == '*')
                preVal *= parse(s, ++i);
            else if(op == '/')
                preVal /= parse(s, ++i);
        }
        return total;
    }
    
private:
    int parse(string& s, int& pos) {
        while(pos < s.size() && isspace(s[pos])) pos++;
        int num = 0;
        while(pos < s.size() && isdigit(s[pos]))
            num = 10 * num + (s[pos++] - '0');
        pos--;
        return num;
    }
};
