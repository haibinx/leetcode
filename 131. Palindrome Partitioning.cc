// https://leetcode.com/problems/palindrome-partitioning/#/description
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> res;
        dfs(s, 0, res, ans);
        return ans;
    }
    
    void dfs(string& s, int pos, vector<string>& res, vector<vector<string>>& ans) {
        if (pos == s.size()) {
            ans.push_back(res);
            return;
        }
        for (int i = pos; i < s.size(); i++) {
            string t = s.substr(pos, i - pos + 1);
            if (isValid(t)) {
                res.push_back(t);
                dfs(s, i+1, res, ans);
                res.pop_back();
            }
        }
    }
    
    bool isValid(string& s) {
        int i = 0, j = s.size() -1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};
