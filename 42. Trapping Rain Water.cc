// https://leetcode.com/problems/trapping-rain-water/#/description
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int n = height.size();
        int l = 0, r = n -1, res = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                int h = height[l];
                l++;
                while (l < r && height[l] < h) {
                    res += h - height[l++];
                }
            } else {
                int h = height[r];
                r--;
                while (l < r && height[r] < h) {
                    res += h - height[r--];
                }
            }
        }
        return res;
    }
    
    // Solution 2
    int trap2(vector<int>& height) {
        if (height.empty()) return 0;
        int n = height.size();
        vector<int> left(n);
        int maxLeft = -1;
        left[0] = -1;
        for (int i = 1; i <n; i++) {
            left[i] = maxLeft = max(maxLeft, height[i-1]);
        }
        
        int ans = 0;
        int maxRight = -1;
        for (int i = n-2; i>=0; i--) {
            maxRight = max(maxRight, height[i+1]);
            int h = min(left[i], maxRight) - height[i];
            ans += h > 0 ? h : 0;
        }
        return ans;
    }
};
