// https://leetcode.com/problems/container-with-most-water/#/description
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxA = 0;
        while (i < j) {
            maxA = max(maxA, min(height[i], height[j]) * (j - i));
            if (height[i] > height[j]) {
                while (j > 0 && height[j-1] < height[j]) j--;
                j--;
            } else {
                while(i< height.size()-1 && height[i+1] < height[i]) i++;
                i++;
            }
        }
        return maxA;
    }
};
