// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/#/description
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 ||matrix[0].empty()) return 0;
        int Max = 0;
        vector<vector<int>> cache(matrix.size(), vector<int>(matrix[0].size(),0));
        for(int i = 0; i< matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                Max = max(DFS(matrix, i, j, INT_MIN, cache), Max);
        return Max;
    }
    
    int DFS(vector<vector<int>>& matrix, int row, int col, int prev, vector<vector<int>>& cache) {
        if (matrix[row][col] <= prev) return 0;
        if (cache[row][col] > 0) return cache[row][col];
        cache[row][col] = 1;
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto& p : dir) {
            int newRow = row + p.first;
            int newCol = col + p.second;
            if (newRow < 0 || newRow >= matrix.size() || newCol < 0 || newCol >= matrix[0].size()) continue;
            cache[row][col] = max(cache[row][col], DFS(matrix, newRow, newCol, matrix[row][col], cache) + 1);
        }
        return cache[row][col];
    }
};
