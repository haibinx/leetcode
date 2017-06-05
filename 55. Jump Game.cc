// https://leetcode.com/problems/jump-game/#/description
class Solution {
public:
    bool canJump(vector<int>& nums) {
    int reach=0;
    int i;
    for( i=0;i<nums.size()&&i<=reach;i++)
    {
        reach=max(reach,i+nums[i]);
    }
    return (i==nums.size());
    }
};
