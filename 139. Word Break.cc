// https://leetcode.com/problems/word-break/#/description
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() +1);
        if(wordDict.size() != 0) dp[0] = true;
        for (int i = 1; i < s.size() + 1; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (dp[j]) {
                    string t = s.substr(j, i-j);
                    if (dict.find(t) != dict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
    
    //Solution 2
    bool wordBreak2(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return dfs(s, dict);
    }
    
    unordered_map<string, bool> mp;
    bool dfs(string s, unordered_set<string>& dict) {
        if (dict.find(s) != dict.end()) return true;
        if (mp.find(s) != mp.end()) return mp[s];
        for (int i = 0; i < s.size(); i++) {
            string t = s.substr(0, i+1);
            if (dict.find(t) == dict.end()) continue;
            if (dfs(s.substr(i+1), dict)) {
                return mp[s] = true;
            }
        }
        return mp[s] = false;
    }
};
