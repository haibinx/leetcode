// https://leetcode.com/problems/decode-ways/#/description
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s == "0") return 0;
        int n = s.size();
        vector<int> dp(n+1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++ ) {
            if (s[i-1] == '0') {
               dp[i] = 0;
           } else {
            dp[i] = dp[i-1];
           }
           if (i > 1 && (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7') )) {
               dp[i] += dp[i-2];
           }
        }
        return dp[n];
    }
    
    int numDecodings1(string s) {
        if (s.empty() || s == "0") return 0;
        int n = s.size();
        int ans = 1;
        int prev;
        for (int i = 1; i <= n; i++ ) {
            int temp = ans;
            if (s[i-1] == '0') {
               ans = 0;
           }
           if (i > 1 && (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7') )) {
               ans += prev;
           }
           prev = temp;
        }
        return ans;
    }
};
