// https://leetcode.com/problems/freedom-trail/#/description
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        // dp[i][j] means the minimum steps from key[i] and ring[j].
        // dp[i][j] = Math.min(dp[i][j], step + dp[i + 1][k])，step is the minimum steps spinning from ring[j] to ring[k]，where key[i]=ring[k];
        vector<vector<int>> dp(m+1, vector<int>(n));
        for (int i = m-1; i >=0; i--) {
            for (int j = 0; j < n ; j++) {
                dp[i][j] = INT_MAX;
                for (int k = 0; k < n; k++) {
                    if (ring[k] == key[i]) {
                        int diff = abs(j - k);
                        int step = min(diff, n - diff);
                        dp[i][j] = min(dp[i][j], step + dp[i + 1][k]);
                    }
                }
            }
        }
        return dp[0][0] + m;
    }
    
    //Solution 2
    unordered_map<string, unordered_map<int, int>> mp;
    int findRotateSteps2(string ring, string key) {
        if (ring.empty() || key.empty()) return 0;
        return dfs(ring, key, 0);
    }
    
    int dfs(string ring, string key, int pos) {
        if (pos == key.size()) return 0;
        if (mp.find(ring) != mp.end()) {
            if (mp[ring].find(pos) != mp[ring].end()) {
                return mp[ring][pos];
            }
        }
        char k = key[pos];
        int first = ring.find_first_of(k);
        int last = ring.find_last_of(k);
        int firstStep = 1 + first + dfs(rollString(ring, first), key, pos+1);
        int lastStep = 1 + ring.size() - last + dfs(rollString(ring, last), key, pos+1);
        int step = min(firstStep, lastStep);
        mp[ring][pos] = step;
        return step;
    }
    
    string rollString(string s, int idx) {
        idx = idx % s.size();
        if (idx == 0) return s;
        return s.substr(idx) + s.substr(0, idx);
    }
};
