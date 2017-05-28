// https://leetcode.com/problems/russian-doll-envelopes/#/description
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if (!n) return 0;
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int>& x, pair<int, int>& y) {
            return x.first != y.first ? x.first < y.first : x.second > y.second;
        });
        vector<int> dp(n, 0);
        vector<int> g(n+1, INT_MAX);
        for (int i = 0; i < n; i++) {
			int k = lower_bound(++g.begin(), g.end(), envelopes[i].second) - g.begin();
			dp[i] = k;
			g[k] = envelopes[i].second;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) ans = max(ans, dp[i]);
		return ans;
    }
};
