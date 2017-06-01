// https://leetcode.com/problems/jump-game-ii/#/description
class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0;
        int reach = 0;
        int n = nums.size();
        int cur = 0;
        while(reach < n -1) {
            int lastReach = reach;
            while(cur <= lastReach) {
                reach = max(cur+nums[cur], reach);
                cur++;
            }
            steps++;
        }
        return steps;
    }
};
