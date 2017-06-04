// https://leetcode.com/problems/game-of-life/#/description
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
       if (board.empty() || board[0].empty()) return;
       int m = board.size(); int n = board[0].size();
       for (int i = 0; i < m; i++) {
           for (int j = 0; j < n; j++) {
               vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
               int liveN = 0;
               for (auto& p : dir) {
                   int newR = i + p.first;
                   int newC = j + p.second;
                   if (newR < 0 || newR > m -1 || newC < 0 || newC > n-1) continue;
                   liveN += (board[newR][newC] & 1);
               }
               if (board[i][j]) {
                   if (liveN < 2 || liveN > 3) board[i][j] &= 1;
                   else board[i][j] |= 2;
               } else {
                   if (liveN == 3) board[i][j] |= 2;
                   else board[i][j] &= 1;
               }
           }
       }
        for (int i = 0; i < m; i++) {
           for (int j = 0; j < n; j++) {
               board[i][j] >>= 1;
           }
        }
    }
};
