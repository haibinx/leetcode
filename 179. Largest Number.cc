// https://leetcode.com/problems/largest-number/#/description
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return stol(to_string(a) + to_string(b)) > stol(to_string(b) + to_string(a));
        });
        
        string ans = "";
        for (int i : nums) {
            ans += to_string(i);
        }
        auto it = ans.find_first_not_of('0');
        if (it == string::npos) return "0";
        return ans.substr(it);
    }
};
