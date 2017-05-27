// https://leetcode.com/problems/max-sum-of-sub-matrix-no-larger-than-k/#/description
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return 0;
		int ans = INT_MIN,m = matrix.size(), n = matrix[0].size(),row_first=true;
		if (m > n) {
			swap(m, n);
			row_first = false;
		}
		for (int ri = 0; ri < m; ri++) {
		    vector<int> temp(n, 0);
		    for (int i = ri; i >=0; i--) {
		        set<int> st;
		        int sum = 0;
		        st.insert(sum);
		        for (int j =0; j < n; j++) {
		            temp[j] += row_first ? matrix[i][j] : matrix[j][i];
		            sum += temp[j];
		            auto it = st.lower_bound(sum - k);
		            if (it != st.end()) {
		                ans = max(ans, sum - *it);
		            }
		            st.insert(sum);
		        }
		    }
		}
		return ans;
    }
};
