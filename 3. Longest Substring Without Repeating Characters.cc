// https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, left = 0, n = s.size();
        vector<int> last(255, -1);
        
        for (int i = 0; i < n; i++) {
            if (last[s[i]] >= left) left = last[s[i]] + 1;
            ans = max(ans, i - left + 1);
            last[s[i]] = i;
        }
        return ans;
    }
};
