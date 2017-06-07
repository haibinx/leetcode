// https://leetcode.com/problems/wiggle-sort-ii/#/description
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;

        // Index-rewiring.
        #define A(i) nums[(1+2*(i)) % (n|1)]

        // 3-way-partition-to-wiggly in O(n) time with O(1) space.
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid)
                swap(A(i++), A(j++));
            else if (A(j) < mid)
                swap(A(j), A(k--));
            else
                j++;
        }        
    }

    // Solution 2
    void wiggleSort2(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int j = (n +1) / 2 -1, k = n -1;
        for (int i = 0; i < n; i++) {
            nums[i] = (i & 1) ? temp[k--] : temp[j--];
        }
    }
};
