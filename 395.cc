// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/#/description
class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int> mp;
        for (char c: s) {
            mp[c]++;
        }
        vector<int> pos;
        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]] < k) {
                pos.push_back(i);
            }
        }
        if (pos.empty()) return s.size();
        int ans = 0;
        pos.insert(pos.begin(), -1);
        pos.push_back(s.size());
        for (int i = 0; i < pos.size() -1; i++) {
            if (pos[i+1] > pos[i] + 1) {
                ans = max(ans, longestSubstring(s.substr(pos[i] + 1, pos[i+1] - pos[i] - 1), k));
            }
        }
        return ans;
    }
};
