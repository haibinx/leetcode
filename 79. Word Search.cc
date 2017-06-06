// https://leetcode.com/problems/word-search/#/description
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        int m = board.size();
        if (m == 0) return false;
        int n = board[0].size();
        if (n == 0) return false;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i =0; i< m; i++) {
            for (int j =0;j < n; j++) {
                if (dfs(board, word, 0, i, j, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int pos, int i, int j, vector<vector<bool>>& visited) {
        if (pos == word.length()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        if (visited[i][j]) return false;
        if (board[i][j] != word[pos]) return false;
        visited[i][j] = true;
        bool ret = dfs(board, word, pos+1, i-1, j, visited) ||
                   dfs(board, word, pos+1, 1+i, j, visited) ||
                   dfs(board, word, pos+1, i, j-1, visited) ||
                   dfs(board, word, pos+1, i, j+1, visited);
        visited[i][j] = false;
        return ret;
    }
};
