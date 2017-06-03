// https://leetcode.com/problems/subsets/#/description
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        dfs(nums, 0, res, ans);
        return ans;
    }
    
    void dfs(vector<int>& nums, int pos, vector<int>& res, vector<vector<int>>& ans) {
        if (pos == nums.size()) {
            ans.push_back(res);
            return;
        }
        
        dfs(nums, pos+1, res, ans);
        res.push_back(nums[pos]);
        dfs(nums, pos+1, res, ans);
        res.pop_back();
    }
};
