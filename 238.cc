// https://leetcode.com/problems/product-of-array-except-self/#/description
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for (int i = 1; i < n; i++) {
            left[i] = left[i-1] * nums[i-1];
        }
        vector<int> ans(n);
        ans[n-1] = left[n-1];
        for (int i = n-2; i>=0; i--) {
            right[i] = right[i+1] * nums[i+1];
            ans[i] = left[i] * right[i];
        }
        return ans;
    }

    // Solution 2
    vector<int> productExceptSelf2(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i-1] * nums[i-1];
        }
        int right = 1;
        for (int i = n-2; i>=0; i--) {
            right = right * nums[i+1];
            ans[i] *= right;
        }
        return ans;
    }
};
