// https://leetcode.com/problems/remove-invalid-parentheses/#/description
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        dfs(s, ')', 0, ans);
        return ans;
    }
    
    void dfs(string s, char ch, int last, vector<string>& ans) {
        for(int i = 0, cnt = 0; i < s.size(); i++)  
        {  
            if(s[i]=='('||s[i]==')') s[i]==ch?cnt++:cnt--;  
            if(cnt <= 0) continue;  
            for(int j = last; j <= i; j++)  
            {  
                if(s[j] == ch && (j ==last || s[j-1]!= ch))  
                    dfs(s.substr(0, j)+s.substr(j+1), ch, j, ans);  
            }  
            return;  
        }  
        reverse(s.begin(), s.end());  
        if(ch == ')') return dfs(s, '(', 0, ans);  
        ans.push_back(s);
    }
};
