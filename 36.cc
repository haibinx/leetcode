// https://leetcode.com/problems/valid-sudoku/#/description
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> cols(9);
        vector<unordered_set<int>> blocks(9);
        for (int i = 0; i < 9; i++) {
            unordered_set<int> s;
            for (int j = 0; j < 9; j++) {
                if (isdigit(board[i][j])) {
                    int t = board[i][j] - '0';
                    if (s.find(t) != s.end()) return false;
                    s.insert(t);
                    if (cols[j].find(t) != cols[j].end()) return false;
                    cols[j].insert(t);
                    int idx = i/3 * 3 + j/3;
                    if (blocks[idx].find(t) != blocks[idx].end()) return false;
                    blocks[idx].insert(t);
                }
            }
        }
        return true;
    }
};
