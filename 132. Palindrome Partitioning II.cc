https://leetcode.com/problems/palindrome-partitioning-ii/#/description
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1);
        for (int i = 0; i <=n; ++i) cut[i] = i - 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; i-j >=0 && i+j < n && s[i-j] == s[i+j]; ++j)
                cut[i+j+1] = min(cut[i+j+1], cut[i-j] + 1);
            for (int j = 1; i - j + 1 >=0 && i + j < n && s[i-j+1] == s[i+j]; ++j)
                cut[i+j+1] = min(cut[i+j+1], cut[i-j+1] + 1);
        }
        return cut[n];
    }
    
    // Solution 2
    int minCut2(string s) {
            if(s.empty()) return 0;
            int n = s.size();
            vector<vector<bool>> pal(n,vector<bool>(n,false));
            vector<int> d(n);
            for(int i=n-1;i>=0;i--)
            {
                d[i]=n-i-1;
                for(int j=i;j<n;j++)
                {
                    if(s[i]==s[j] && (j-i<2 || pal[i+1][j-1]))
                    {
                       pal[i][j]=true;
                       if(j==n-1)
                           d[i]=0;
                       else if(d[j+1]+1<d[i])
                           d[i]=d[j+1]+1;
                    }
                }
            }
            return d[0];
        }
};
