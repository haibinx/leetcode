// https://leetcode.com/problems/shortest-palindrome/#/description
class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string t= s + '#' + r + "$";
        vector<int> next = KMP(t);
        return r.substr(0, s.size() - next.back()) + s;
    }
    
    vector<int> KMP(string& p) {
        vector<int> next(p.size(), -1);
        int pLen = p.size();  
        int k = -1;  
        int j = 0;  
        while (j < pLen - 1)  {   
            if (k == -1 || p[j] == p[k]) {  
                ++k;  
                ++j;  
                next[j] = k;  
            } else {  
                k = next[k];  
            }
        }
        return next;
    }
};
