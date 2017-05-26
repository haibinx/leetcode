class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<int> res;
        dfs(n, 0, res, ans);
        return ans;
    }
    
    void dfs(int n, int pos, vector<int>& res, int& ans) {
        if (pos == n) {
            ans++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(i, res)) {
                res.push_back(i);
                dfs(n, pos+1, res, ans);
                res.pop_back();
            }
        }
    }
    
    bool isValid(int pos, vector<int>& res) {
        int curr_row = res.size();
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == pos) return false;
            if (abs(res[i] - pos) == curr_row - i) return false;
        }
        return true;
    }
};
