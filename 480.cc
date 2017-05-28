// https://leetcode.com/problems/sliding-window-median/#/description
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<int> s;
        for(int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
            if (s.size() == k) {
                auto it = s.begin();
                advance(it, (k-1) / 2);
                if ((k & 1) == 0) {
                    ans.push_back(((double)*it + *(++it)) / 2.0);
                } else {
                    ans.push_back(*it);
                }
                s.erase(s.lower_bound(nums[i-k+1]));
            }
        }
        return ans;
    }
};
