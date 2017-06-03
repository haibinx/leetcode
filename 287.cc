// https://leetcode.com/problems/find-the-duplicate-number/#/description
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size() -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) /2;
            int cnt = 0;
            for (int i : nums) {
                if (i <= mid) cnt++;
            }
            if (cnt <= mid) lo = mid +1;
            else hi = mid -1;
        }
        return lo;
    }
    
    // Solution 2
    int findDuplicate2(vector<int>& nums) {
        int slow = 0, fast = 0;
        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        
        fast = 0;
        while(true) {
            slow = nums[slow];
            fast = nums[fast];
            
            if (slow == fast) return slow;
        }
    }
};
