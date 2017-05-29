// https://leetcode.com/problems/concatenated-words/#/description
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> ans;
        for (string& w : words) {
            if (match(w, dict, true)) {
                ans.push_back(w);
            }
        }
        return ans;
    }
    
    unordered_map<string, bool> mp;
    bool match(string w, unordered_set<string>& dict, bool start) {
        if (!start && mp.find(w) != mp.end()) return mp[w];
        if (!start && dict.find(w) != dict.end()) {
            mp[w] = true;
            return true;
        }
        for (int i = 1; i < w.size(); i++) {
            string prefix = w.substr(0, i);
            if (dict.find(prefix) != dict.end()) {
                if (match(w.substr(i), dict, false)) {
                    if (!start) {
                        mp[w] = true;
                    }
                    return true;
                }
            }
        }
        if (!start) mp[w] = false;
        return false;
    }
};
