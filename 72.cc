// https://leetcode.com/problems/edit-distance/#/description
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        if (word1.empty()) return n2;
        if (word2.empty()) return n1;
        vector<vector<int>> dp(n1+1, vector<int>(n2+1));
        for (int i = 0; i <= n1; i++) dp[i][0] = i;
        for (int j = 0; j <= n2; j++) dp[0][j] = j;
        for (int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i-1][j-1] +1;
                }
                dp[i][j] = min(dp[i][j], min(dp[i-1][j] + 1, dp[i][j-1] +1));
            }
        }
        return dp[n1][n2];
    }
};
