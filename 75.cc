// https://leetcode.com/problems/sort-colors/#/description
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, hi = nums.size() -1;
        int i = 0;
        while(i <= hi) {
            if (nums[i] == 0 && i != lo) {
                swap(nums[lo], nums[i]);
                lo++;
            } else if (nums[i] == 2 && i != hi) {
                swap(nums[hi], nums[i]);
                hi--;
            } else {
                i++;
            }
        }
    }
};
