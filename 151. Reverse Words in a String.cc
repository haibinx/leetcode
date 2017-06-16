// https://leetcode.com/problems/reverse-words-in-a-string/#/description
class Solution {
public:
    void reverseWords(string &s) {
        int n = s.size();
        int left = 0;
        while(left < n && s[left] == ' ') left++;
        if (left == n) {
            s = "";
            return;
        }
        
        int right = n -1;
        while(s[right] == ' ') right--;
        s.erase(s.begin() + right + 1, s.end());
        s.erase(s.begin(), s.begin() + left);

        reverse(s.begin(), s.end());
        left = 0;
        right = s.size() - 1;
        while(left <= right) {
            int i = left + 1;
            while(i <= right && s[i] != ' ') i++;
            reverse(s.begin() + left, s.begin() + i);
            int j = i;
            while(j <= right && s[j] == ' ') j++;
            if (j - i > 1) {
                s.erase(s.begin() + i, s.begin() + j - 1);
                right -= j - i - 1;
            }
            left = i + 1;
        }
    }
};
