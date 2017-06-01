// https://leetcode.com/problems/count-the-repetitions/#/description
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int ans = 0;
        int pos2 = 0;
        unordered_map<int, pair<int, int>> mem; 
        for (int loop1 = 0; loop1 < n1;) {
            for (int pos1 = 0; pos1< s1.size(); pos1++) {
                if (s1[pos1] == s2[pos2]) {
                    pos2++;
                    if (pos2 == s2.size()) {
                        pos2 = 0;
                        ans++;
                        if (mem.find(pos1) != mem.end()) {
                            int ans0 = mem[pos1].second;
                            int loop10 = mem[pos1].first;
                            int n = (n1 -1 -loop10) / (loop1 - loop10);
                            ans = n * (ans - ans0) + ans0;
                            loop1 = n * (loop1 - loop10) + loop10;
                        } else {
                            mem[pos1] = make_pair(loop1, ans);
                        }
                    }
                }
            }
            loop1++;
        }
        return ans / n2;
    }
    
    // Solution 2
    int getMaxRepetitions2(string s1, int n1, string s2, int n2) {
        vector<int> repeatCnt(s2.size() + 1, 0);
        vector<int> nextIdx(s2.size() + 1, 0);
        int j = 0, cnt = 0;
        for (int k = 1; k <= n1; ++k) {
            for (int i = 0; i < s1.size(); ++i) {
                if (s1[i] == s2[j]) {
                    ++j;
                    if (j == s2.size()) {  
                        j = 0;
                        ++cnt;
                    }
                }
            }
            repeatCnt[k] = cnt;
            nextIdx[k] = j;
            for (int start = 0; start < k; ++start) {
                if (nextIdx[start] == j) {
                    int interval = k - start;
                    int repeat = (n1 - start) / interval;
                    int patternCnt = (repeatCnt[k] - repeatCnt[start]) * repeat;
                    int remainCnt = repeatCnt[start + (n1 - start) % interval];
                    return (patternCnt + remainCnt) / n2;
                }
            }
        }
        return repeatCnt[n1] / n2;
    }
};
