// https://leetcode.com/problems/coin-change/#/description
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (coins.empty()) return -1;
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for ( int j : coins) {
                if (i >= j && dp[i-j] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i-j] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
