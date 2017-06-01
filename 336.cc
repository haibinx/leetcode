// https://leetcode.com/problems/palindrome-pairs/#/description
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> m;
        set<int> s;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            m[words[i]] = i;
            s.insert(words[i].size());
        }
        
        for (int i = 0; i < n; i++) {
            string word = words[i];
            int len = word.size();
            
            reverse(word.begin(), word.end());
            if (m.find(word) != m.end() && m[word] != i) {
                res.push_back({i, m[word]});
            }

            auto a = s.find(len);
            for (auto it = s.begin(); it != a; ++it) {
                int d = *it;
                if (isValid(word, 0, len - d - 1) && m.find(word.substr(len - d)) != m.end()) {
                    res.push_back({i, m[word.substr(len - d)]});
                }
                if (isValid(word, d, len - 1) && m.find(word.substr(0, d)) != m.end()) {
                    res.push_back({m[word.substr(0, d)], i});
                }
            }
        }
        return res;
    }
    bool isValid(string t, int left, int right) {
        while (left < right) {
            if (t[left++] != t[right--]) return false;
        }
        return true;
    }
};
