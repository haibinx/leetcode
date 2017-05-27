// https://leetcode.com/problems/trapping-rain-water-ii/#/description
class Solution {
public:
    struct Cmp {
       bool operator() (pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
           return a.second > b.second;
       }
    };
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, Cmp> pq;
        
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for (int i =0; i < m; i++) {
            pq.push(make_pair(make_pair(i, 0), heightMap[i][0]));
            visit[i][0] = true;
            pq.push(make_pair(make_pair(i, n-1), heightMap[i][n-1]));
            visit[i][n-1] = true;
        }
        
        for (int i =0; i < n; i++) {
            pq.push(make_pair(make_pair(0, i), heightMap[0][i]));
            visit[0][i] = true;
            pq.push(make_pair(make_pair(m-1, i), heightMap[m-1][i]));
            visit[m-1][i] = true;
        }
        
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int ans = 0;
        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            for (int i = 0; i < 4; i++) {
                int row = t.first.first + dir[i][0];
                int col = t.first.second + dir[i][1];
                if (row >= 0 && row < m && col >=0 && col < n && !visit[row][col]) {
                    visit[row][col] = true;
                    ans += max(0, t.second - heightMap[row][col]);
                    pq.push(make_pair(make_pair(row, col), max(t.second, heightMap[row][col])));
                }
            }
        }
        return ans;
    }
};
