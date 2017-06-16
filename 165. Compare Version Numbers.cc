// https://leetcode.com/problems/compare-version-numbers/#/description
class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream iss1(version1 + '.');
        istringstream iss2(version2 + '.');
        
        int n1 = 0, n2 = 0;
        char dot;
        while(!iss1.eof() || !iss2.eof()) {
            if (!iss1.eof()) {
                iss1 >> n1 >> dot;
            }
            if (!iss2.eof()) {
                iss2 >> n2 >> dot;
            }
            
            if (n1 > n2) return 1;
            if (n1 < n2) return -1;
            n1 = n2 = 0;
        }
        return 0;
    }
};
