https://leetcode.com/problems/regular-expression-matching/#/description
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())    return s.empty();
        
        if ('*' == p[1])
            // x* matches empty string or at least one character: x* -> xx*
            // *s is to ensure s is non-empty
            return (isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
        else
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
    }

    // Solution 2
    bool isMatch2(string s, string p) {
        int lens = s.length(), lenp = p.length();
        vector<vector<int>> dp(lens+1, vector<int>(lenp+1, false));
        dp[0][0] = true;
        for (int si = 0; si <= lens; si++) {
            for (int pi = 1; pi <= lenp; pi++) {
                if (p[pi-1] == '*') {
                    dp[si][pi] = (pi > 1 && dp[si][pi-2]) || 
                                 (si > 0 &&  (p[pi-2] == '.' || p[pi-2] == s[si-1]) &&dp[si-1][pi]);
                } else {
                    if (si > 0 && (p[pi-1] == '.' || p[pi-1] == s[si-1])) dp[si][pi] = dp[si-1][pi-1];
                    else dp[si][pi] = false;
                }
            }
        }
        
        return dp[lens][lenp];
    }
};
