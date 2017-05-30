// https://leetcode.com/problems/remove-duplicate-letters/#/description
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26);
        for (char c : s) {
            cnt[c-'a']++;
        }
        vector<bool> visited(26, false);
        string ans = "A";
        for (int i = 0; i < s.size(); ++i) {
            cnt[s[i] - 'a']--;
            if (visited[s[i]-'a']) continue;
            while (s[i] < ans.back() && cnt[ans.back() - 'a']) {
                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans += s[i];
            visited[s[i]-'a'] = true;
        }
        return ans.substr(1);
    }
};
