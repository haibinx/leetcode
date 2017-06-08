// https://leetcode.com/problems/3sum/#/description
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n -2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1, k = n - 1;
            int needed = -nums[i];
            while (j < k) {
                if (nums[j] + nums[k] == needed) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    k--;
                    while(k > j && nums[k] == nums[k+1]) k--;
                } else if (nums[j] + nums[k] < needed) {
                    j++;
                    while(j < k && nums[j] == nums[j-1]) j++;
                } else {
                    k--;
                    while(k > j && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};
