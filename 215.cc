// https://leetcode.com/problems/kth-largest-element-in-an-array/#/description
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int i : nums) {
            pq.push(i);
        }
        while (--k > 0) {
            pq.pop();
        }
        return pq.top();
    }
};
