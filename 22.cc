// https://leetcode.com/problems/generate-parentheses/#/description
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(n, n, "", ans);
        return ans;
    }
    
    void dfs(int left, int right, string res, vector<string>& ans) {
        if (left == 0 && right == 0) {
            ans.push_back(res);
            return;
        }
        if (left < 0 || right < 0 || left > right) {
            return;
        }
        
        dfs(left -1, right, res +"(", ans);
        dfs(left, right-1, res + ")", ans);
    }
};
