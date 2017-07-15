https://leetcode.com/problems/median-of-two-sorted-arrays/#/description
class Solution {
public:
    double findKth(vector<int>& A, vector<int>& B, int A_st, int B_st, int k) {
        if (A_st >= A.size()) return B[B_st+ k -1];
        if (B_st >= B.size()) return A[A_st+ k -1];
        if (k == 1) return min(A[A_st], B[B_st]);
        int A_mid = A_st + k/2 -1 >= A.size() ? INT_MAX : A[A_st + k/2 -1];
        int B_mid = B_st + k/2 -1 >= B.size() ? INT_MAX : B[B_st + k/2 -1];
        
        if (A_mid < B_mid) {
            return findKth(A, B, A_st + k/2, B_st, k - k/2);
        } else {
            return findKth(A, B, A_st, B_st + k/2, k - k/2);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        double ret;
        
        if (sum & 1) {
            ret = findKth(nums1, nums2, 0, 0, sum / 2 + 1);
        } else {
            ret = ((findKth(nums1, nums2, 0, 0, sum / 2)) +
                    findKth(nums1, nums2, 0, 0, sum / 2 + 1)) / 2.0;
        }
        return ret;
    }
    
    // Solution 2
    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        if (N1 < N2) return findMedianSortedArrays(nums2, nums1);	// Make sure A2 is the shorter one.
    
        if (N2 == 0) return ((double)nums1[(N1-1)/2] + (double)nums1[N1/2])/2;  // If A2 is empty
    
        int lo = 0, hi = N2 * 2;
        while (lo <= hi) {
            int mid2 = (lo + hi) / 2;   // Try Cut 2 
            int mid1 = N1 + N2 - mid2;  // Calculate Cut 1 accordingly
        
            double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];	// Get L1, R1, L2, R2 respectively
            double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
            double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1)/2];
            double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2)/2];
        
            if (L1 > R2) lo = mid2 + 1;		// A1's lower half is too big; need to move C1 left (C2 right)
            else if (L2 > R1) hi = mid2 - 1;	// A2's lower half too big; need to move C2 left.
            else return (max(L1,L2) + min(R1, R2)) / 2;	// Otherwise, that's the right cut.
        }
        return -1;
    } 
};
