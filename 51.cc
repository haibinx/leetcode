// https://leetcode.com/problems/n-queens/#/description
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> res;
        dfs(n, 0, res, ans);
        return ans;
    }
    
    void dfs(int n, int pos, vector<int>& res, vector<vector<string>>& ans) {
        if (pos == n) {
            vector<string> temp;
            for (int i : res) {
                vector<char> r(n, '.');
                r[i] = 'Q';
                temp.push_back(string(r.begin(), r.end()));
            }
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < n; ++i ) {
            if(isValid(n, res, i)) {
                res.push_back(i);
                dfs(n, pos+1, res, ans);
                res.pop_back();
            }
        }
     }
     
     bool isValid(int n, vector<int>& res, int col) {
         int m = res.size();
         for (int i = 0; i < m; i++) {
             if (res[i] == col) return false;
             if (abs(res[i] - col) == m - i) return false;
         }
         return true;
     }
};
