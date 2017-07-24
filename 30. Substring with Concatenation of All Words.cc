https://leetcode.com/problems/substring-with-concatenation-of-all-words/#/description
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int ss = s.size(), ws = words.size();
        if (ss == 0 || ws == 0) return ans;
        unordered_map<string, int> dict;
        for (int i = 0; i < ws; ++i) dict[words[i]]++; 
        
        int wl = words[0].size();
        for (int i = 0; i < wl; i++) {
            int left = i, count = 0;
            unordered_map<string, int> tdict;
            for (int j = i; j <= ss -wl; j+= wl) {
                string str = s.substr(j, wl);
                if (dict.find(str) != dict.end()) {
                    tdict[str]++;
                    if (tdict[str] <= dict[str]) 
                        count++;
                    else {
                        while(tdict[str] > dict[str]) {
                            string str1 = s.substr(left, wl);
                            tdict[str1]--;
                            if (tdict[str1] < dict[str1]) count--;
                            left += wl;
                        }
                    }
                    if (count == ws) {
                        ans.push_back(left);
                        tdict[s.substr(left, wl)]--;
                        count--;
                        left += wl;
                    }
                } else {
                    count = 0;
                    tdict.clear();
                    left = j + wl;
                }
            }
        }
        return ans;
    }
};
