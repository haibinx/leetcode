// https://leetcode.com/problems/sudoku-solver/#/description
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int, int>> empties;
        for (int i = 0;i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    empties.emplace_back(i, j);
                }
            }
        }
        bool solved = false;
        dfs(board, empties, 0);
    }
    
    bool dfs(vector<vector<char>>& board, vector<pair<int, int>>& empties, int pos) {
        if (pos == empties.size()) {
            return true;
        }
        auto p = empties[pos];
        int row = p.first;
        int col = p.second;
        for (int i = 1; i <= 9; i++) {
            if (isValid(board, row, col, i)) {
                board[row][col] = '0' + i;
                if (dfs(board, empties, pos+1)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, int number) {
        for(int i = 0; i < 9; i++) {
            if (board[row][i] == '0' + number) return false;
            if (board[i][col] == '0' + number) return false;
        }
        
        int row_base = (row/3) * 3;
        int col_base = (col/3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[row_base+i][col_base+j] == '0' + number) return false;
            }
        }
        return true;
    }
};
