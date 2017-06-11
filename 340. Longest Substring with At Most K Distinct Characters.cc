// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ans = 0, left = 0;
	unordered_map<char, int> mp;
	for (int i = 0; i < s.size(); i++) {
	    mp[s[i]]++;
	    while (mp.size() > k) {
		if (--mp[s[left]] == 0) {
		    mp.erase(s[left];
		left++;
	    }
	    ans = max(ans, i - left + 1);
	}
	return ans;
    }
};
