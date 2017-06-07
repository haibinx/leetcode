// https://leetcode.com/problems/longest-palindromic-substring/#/description
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        int start = 0, maxLen = 1;
        
        for(int i=n-1; i>=0; i--) {
            for(int j=i; j<n; j++) {
                if((i+1>j-1 || isPal[i+1][j-1]) && s[i]==s[j]) {
                    isPal[i][j] = true;
                    if(j-i+1>maxLen) {
                        maxLen = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }

    string longestPalindrome2(string s) {
        int n = s.size();
        if (n <= 1) return s;
        int maxLen = 1;
        int i = 0;
        string res = s.substr(0, 1);
        while ( i < n - maxLen / 2) {
            int j = i, k = i;
            while(k < n -1 && s[k] == s[k+1]) k++;
            i = k + 1;
            while (k < n -1 && j > 0 && s[k+1] == s[j-1]) {
                k++;
                j--;
            }
            if (k -j + 1 > maxLen) {
                maxLen = k - j + 1;
                res = s.substr(j, maxLen);
            }
        }
        return res;
    }
};
