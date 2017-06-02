// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/#/description
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                pq.push(matrix[i][j]);
            }
        }
        while (--k > 0) {
            pq.pop();
        }
        return pq.top();
    }
    
    // Solution 2
    int kthSmallest2(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int l=matrix[0][0],r=matrix[n-1][n-1];
        while(l<r){
            int mid=l+(r-l)/2;
            int num=0;
            for(int i=0;i<n;i++){
                int pos=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
                num+=pos;
            }
            if(num<k) l=mid+1;
            else r=mid;
        }
        return l;
    }
};
