// https://leetcode.com/problems/word-ladder/#/description
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        return bfs(beginWord, endWord, dict);
    }
    
    int bfs(string beginWord, string endWord, unordered_set<string>& dict) {
        queue<string> q;
        int step = 2;
        q.push(beginWord);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string s = q.front();
                q.pop();
                for (int j = 0; j < s.size(); j++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        string newWord = s;
                        newWord[j] = c;
                        if (newWord == s) continue;
                        if (dict.find(newWord) == dict.end()) continue;
                        if (newWord == endWord) {
                            return step;
                        }
                        dict.erase(newWord);
                        q.push(newWord);
                    }
                }
            }
            step++;
        }
        return 0;
    }
};
