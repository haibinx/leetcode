// https://leetcode.com/problems/evaluate-reverse-polish-notation/#/description
class Solution {
public:
 int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int n2 = s.top(); s.pop();
                int n1 = s.top(); s.pop();
                if (token == "+") s.push(n1 + n2);
                if (token == "-") s.push(n1 - n2);
                if (token == "*") s.push(n1 * n2);
                if (token == "/") s.push(n1 / n2);
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
