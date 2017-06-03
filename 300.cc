// https://leetcode.com/problems/longest-increasing-subsequence/#/description
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    
    // Solution 2
    int lengthOfLIS2(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for (int i : nums) {
            auto it = lower_bound(res.begin(), res.end(), i);
            if (it == res.end()) res.push_back(i);
            else *it = i;
        }
        return res.size();
    }
};
