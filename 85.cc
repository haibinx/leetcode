// https://leetcode.com/problems/maximal-rectangle/#/description
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> height(n+1);
        int ans = 0;
        for (int i = 0; i < m ; i++) {
            stack<int> s;
            for (int j = 0; j < n+1; j++) {
                if (j < n) {
                    if (matrix[i][j] == '1') {
                        height[j] = height[j] + 1;
                    } else {
                        height[j] = 0;
                    }
                }
                if (!s.empty() && height[j] < height[s.top()]) {
                    int k = j -1;
                    while(!s.empty() && height[s.top()] > height[j]) {
                        int h = height[s.top()];
                        s.pop();
                        ans = max(ans, h * (s.empty() ? j : j - 1 - s.top()));
                    }
                }
                s.push(j);
            }
        }
        return ans;
    }
};
