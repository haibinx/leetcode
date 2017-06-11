// https://leetcode.com/problems/surrounded-regions/#/description
class Solution {
public:
void solve(vector<vector<char>>& board) {
    if (board.empty() || board[0].empty()) return;
    int m = board.size(), n = board[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
        if (board[i][0] == 'O') {
            q.push(make_pair(i, 0));
        }
        if (board[i][n-1] == 'O') {
            q.push(make_pair(i, n-1));
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (board[0][i] == 'O') {
            q.push(make_pair(0, i));
        }
        if (board[m-1][i] == 'O') {
            q.push(make_pair(m-1, i));
        }
    }
    
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        board[p.first][p.second] = 'E';
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0,1}};
        for (auto& d : dir) {
            int newRow = p.first + d.first;
            int newCol = p.second + d.second;
            if (newRow < 0 || newRow >= board.size() || newCol < 0 || newCol >= board[0].size()) continue;
            if (board[newRow][newCol] == 'O') {
                q.push(make_pair(newRow, newCol));
            }
        }
    }
    
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if (board[i][j] == 'E') {
                board[i][j] = 'O';
            }
        }
    }
}

void solve1(vector<vector<char>>& board) {
    if (board.empty() || board[0].empty()) return;
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i) {
        if (board[i][0] == 'O') {
            dfs(board, i, 0);
        }
        if (board[i][n-1] == 'O') {
            dfs(board, i, n-1);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (board[0][i] == 'O') {
            dfs(board, 0, i);
        }
        if (board[m-1][i] == 'O') {
            dfs(board, m-1, i);
        }
    }
    
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if (board[i][j] == 'E') {
                board[i][j] = 'O';
            }
        }
    }
}

void dfs(vector<vector<char>>& board, int row, int col) {
    if (board[row][col] != 'O') return;
    board[row][col] = 'E';
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0,1}};
    for (auto& p : dir) {
        int newRow = row + p.first;
        int newCol = col + p.second;
        if (newRow < 0 || newRow >= board.size() || newCol < 0 || newCol >= board[0].size()) continue;
        if (board[newRow][newCol] == 'O') {
            dfs(board, newRow, newCol);
        }
    }
}
};
