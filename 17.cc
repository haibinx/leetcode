// https://leetcode.com/problems/letter-combinations-of-a-phone-number/#/description
class Solution {
public:
    vector<vector<char>> mapping =
    {{},
     {},
     {'a', 'b','c'},
     {'d', 'e', 'f'},
     {'g', 'h', 'i'},
     {'j', 'k', 'l'},
     {'m', 'n', 'o'},
     {'p', 'q', 'r', 's'},
     {'t', 'u', 'v'},
     {'w', 'x', 'y', 'z'}
    };

    vector<string> letterCombinations1(string digits) {
        vector<string> ans;
        dfs(digits, 0, "", ans);
        return ans;
    }
    
    void dfs(string& digits, int pos, string res, vector<string>& ans) {
        if (pos == digits.size()) {
            if (!res.empty()) ans.push_back(res);
            return;
        }
        
        vector<char> m = mapping[digits[pos] - '0'];
        for (char c : m) {
            dfs(digits, pos+1, res + c, ans);
        }
    }
    
    // Solution 2
    vector<string> letterCombinations2(string digits) {
        if (digits.empty()) return vector<string>();
        vector<string> ans;
        ans.push_back("");
        for (char c: digits) {
            int n = ans.size();
            for (char m : mapping[c - '0']) {
                for (int i = 0; i < n; i++) {
                    ans.push_back(ans[i] + m);
                }
            }
            ans.erase(ans.begin(), ans.begin() + n);
        }
        return ans;
    }
};
