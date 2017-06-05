// https://leetcode.com/problems/course-schedule/#/description
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> indgree = calc_indgree(graph);
        int i = 0;
        while (i < numCourses) {
            vector<int> zeroDgree;
            for (int j = 0; j < numCourses; j++) {
                if (indgree[j] == 0) {
                    zeroDgree.push_back(j);
                }
            }
            if (zeroDgree.empty()) return false;
            for (int j : zeroDgree) {
                indgree[j] = -1;
                for(int n : graph[j]) {
                    indgree[n]--;
                }
            }
            i += zeroDgree.size();
        }
        return true;
    }
    
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto& p : prerequisites) {
            graph[p.second].insert(p.first);
        }
        return graph;
    }
    
    vector<int> calc_indgree(vector<unordered_set<int>>& graph) {
        vector<int> result(graph.size(), 0);
        for (int i = 0; i < graph.size(); ++i) {
            for (int j : graph[i]) {
                result[j]++;
            }
        }
        return result;
    }
};
