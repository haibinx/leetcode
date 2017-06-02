// https://leetcode.com/problems/top-k-frequent-elements/#/description
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        int n = nums.size();
        vector<vector<int>> buckets(n+1);
        for (auto it = mp.begin(); it != mp.end(); it++) {
            buckets[it->second].push_back(it->first);
        }
        
        vector<int> ans;
        for (int i = n; i > 0; i--) {
            for (int num : buckets[i]) {
                ans.push_back(num);
                if (--k == 0) {
                    return ans;
                }
            }
        }
        return ans;
    }
};
