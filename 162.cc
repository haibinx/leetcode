// https://leetcode.com/problems/find-peak-element/#/description
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        nums.insert(nums.begin(), INT_MIN);
        nums.push_back(INT_MIN);
        for (int i = 1; i <=n; ++i ) {
            if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                return i-1;
            }
        }
        return 0;
    }

    Solution 2
    int findPeakElement2(vector<int>& nums) {
        int lo = 0, hi = nums.size() -1;
        while (lo < hi) {
            int mid = lo + (hi-lo) /2;
            if (nums[mid] > nums[mid+1]) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
