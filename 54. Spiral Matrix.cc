// https://leetcode.com/problems/spiral-matrix/#/description
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> res;        
        if (matrix.empty() || matrix[0].empty()) return res;
        int m = matrix.size(), n = matrix[0].size();
        int lb = 0, ub = 0, rb = n -1, db = m - 1;
        int row =0, col = 0;
        int direction = 0;
        for (int i = 0; i < m * n; i++) {
            res.push_back(matrix[row][col]);
            switch(direction) {
                case 0:
                    if (col >= rb) { direction = 1; row++; ub++; } else col++;
                    break;
                case 1:
                    if (row >= db) { direction = 2; col--; rb--; } else row++;
                    break;
                case 2:
                    if (col <= lb) { direction = 3; row--; db--; } else col--;
                    break;
                case 3:
                    if (row <= ub) { direction = 0; col++; lb++; } else row--;
                    break;
            }
        }
        return res;
    }
};
