// https://leetcode.com/problems/maximum-product-subarray/#/description
class Solution {
public:
    int maxProduct(vector<int>& A) {
        if (A.empty()) return 0;
        int maxProduct = A[0], minProduct = A[0];
        int res = A[0];
        for (int i = 1; i < A.size(); i++) {
            int prevMaxProduct = maxProduct;
            maxProduct = max(max(maxProduct*A[i], minProduct*A[i]), A[i]);
            minProduct = min(min(prevMaxProduct*A[i], minProduct*A[i]), A[i]);
            res = max(res, maxProduct);
        }
        return res;
    }
};
