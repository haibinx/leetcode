// https://leetcode.com/problems/longest-valid-parentheses/#/description
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<int, bool>> st;
        int maxLen = 0, curLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(make_pair(i, false));
            } else {
                if (st.empty() || st.top().second) {
                    st.push(make_pair(i, true));
                } else {
                    st.pop();
                    if (st.empty()) {
                        curLen = i + 1;
                    } else {
                        curLen = i - st.top().first;
                    }
                    maxLen = max(maxLen, curLen);
                }
            }
        }
        return maxLen;
    }
    
    // Solution 2
    int longestValidParentheses2(string s) {
        int n = s.size(), maxLen = 0;
        vector<int> dp(n+1);
        for (int i = 1; i <=n; ++i) {
            int j = i - 2 - dp[i-1];
            if (s[i-1] == '(' || j < 0 || s[j] == ')') {
                dp[i] = 0;
            } else {
                dp[i] = 2 + dp[j] + dp[i-1];
                maxLen = max(maxLen, dp[i]);
            }
        }
        return maxLen;
    }
};
