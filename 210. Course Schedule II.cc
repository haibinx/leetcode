// https://leetcode.com/problems/course-schedule-ii/#/description
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ans;
        if(numCourses <= 0) return ans;

        vector<vector<int>> graph(numCourses);
        for (auto& p : prerequisites) {
            graph[p.second].push_back(p.first);
        }
        
        vector<int> indgree(numCourses);
        for(auto& g : graph) {
            for (auto& h: g) {
                indgree[h]++;
            }
        }
        
        int i = 0;
        while (i < numCourses) {
            int n = 0;
            for ( int j = 0; j < numCourses; j++) {
                if (!indgree[j]) {
                    ans.push_back(j);
                    for (int k : graph[j]) {
                        indgree[k]--;
                    }
                    n++;
                    indgree[j] = -1;
                }
            }
            if (n == 0) return vector<int>();
            i += n;
        }
        return ans;
    }
};
