// https://leetcode.com/problems/longest-consecutive-sequence/#/description
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) == s.end()) continue;
            s.erase(nums[i]);
            int len = 1, j = 1;
            while(s.find(nums[i]-j) != s.end()) {
                s.erase(nums[i] - j);
                j++;
            }
            len += j -1;
            j = 1;
            while(s.find(nums[i]+j) != s.end()) {
                s.erase(nums[i] + j);
                j++;
            }
            len += j -1;
            res = max(res, len);
        }
        return res;
    }
};
