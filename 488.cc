// https://leetcode.com/problems/zuma-game/#/description
class Solution {
public:
    int findMinStep(string board, string hand) {
        unordered_map<char, int> mp;
        for (char c: hand) {
            mp[c]++;
        }
        int ans = helper(board, hand.size(), mp);
        return  ans == INT_MAX ? -1 : ans;
    }
    
    int helper(string board, int n, unordered_map<char, int>& mp) {
        board = removeConsecutive(board);
        if (board == "") {
            return 0;
        }
        int ans = INT_MAX;
        for(int i = 0; i < board.size();) {
            int j = i;
            while (j+1 < board.size() && board[j+1] == board[j]) j++;
            int len = j - i +1;
            if (len + mp[board[i]] >= 3) {
                string newboard = board;
                int ball = 3 - len > 0 ? 3 - len : 0;
                if (ball > 0) {
                    newboard.insert(i, ball, board[i]);
                }
                mp[board[i]] -= ball;
                int next = helper(newboard, n - ball, mp);
                if (next != INT_MAX) {
                    ans = min(ans, helper(newboard, n - ball, mp) + ball);
                }
                mp[board[i]] += ball;
            }
            i = j+1;
        }
        return ans;
    }
    
    string removeConsecutive(string board) {
        for (int i = 0, j = 0; i <= board.size(); ++i) {
            if (i < board.size() && board[i] == board[j]) continue;
            if (i - j >= 3) return removeConsecutive(board.substr(0, j) + board.substr(i));
            else j = i;
        }
        return board;
    }
};
