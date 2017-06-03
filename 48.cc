// https://leetcode.com/problems/rotate-image/#/description
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       if (matrix.empty()) return;
       int n = matrix.size();
       // 1 2 3             1 4 7
       // 4 5 6     to      2 5 8
       // 7 8 9             3 6 9
       for (int i = 0; i < n; i++) {
           for (int j = i+1; j < n; j++) {
               swap(matrix[i][j], matrix[j][i]);
           }
       }
       
       // 1 4 7             7 4 1
       // 2 5 8     to      8 5 2
       // 3 6 9             9 6 3
       for (int i = 0; i < n; i++) {
           reverse(matrix[i].begin(), matrix[i].end());
       }
    }
};
