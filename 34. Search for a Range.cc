// https://leetcode.com/problems/search-for-a-range/#/description
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        auto it1 = lower_bound(nums.begin(), nums.end(), target);
        if (it1 == nums.end() || *it1 != target) return ans;
        ans[0] = it1 - nums.begin();
        auto it2 = upper_bound(nums.begin(), nums.end(), target);
        ans[1] = it2 - nums.begin() -1;
        return ans;
    }
    
    // Solution 2
    vector<int> searchRange2(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int lo = 0, hi = nums.size() -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid -1;
            }
        }
        if (lo >= nums.size() || nums[lo] != target) return ans;
        ans[0] = lo;

        hi = nums.size() -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                lo = mid + 1;
            } else {
                hi = mid -1;
            }
        }
        ans[1] = hi;
        return ans;
    }
    
    // Solution 3
    vector<int> searchRange3(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int lo = binarySearch(nums, target - 0.5);
        if (lo >= nums.size() || nums[lo] != target) return ans;
        ans[0] = lo;
        ans[1] = binarySearch(nums, target + 0.5) - 1;
        return ans;
    }
    
    int binarySearch(vector<int>& nums, double target) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid -1;
            }
        }
        return lo;
    }
};
