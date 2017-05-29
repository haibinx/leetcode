// https://leetcode.com/problems/count-of-range-sum/#/description
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int ans = 0;
        int n = nums.size();
        vector<long> sum(n+1, 0);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i-1] + nums[i-1];
        }
        return countWhileMergeSort(sum, 0, n + 1, lower, upper);
    }
    
    int countWhileMergeSort(vector<long>& sums, int start, int end, int lower, int upper) {
        if (end - start <= 1) return 0;
        int mid = start + (end - start) /2;
        int count = countWhileMergeSort(sums, start, mid, lower, upper) 
            + countWhileMergeSort(sums, mid, end, lower, upper);
        int j = mid, k = mid, t = mid, len = 0;
        vector<long> cache(end - start);
        for (int i = start, r =0; i < mid; ++i, ++r) {
            while (k < end && sums[k] - sums[i] < lower) k++;
            while (j < end && sums[j] - sums[i] <= upper) j++;
            while (t < end && sums[t] < sums[i]) cache[r++] = sums[t++];
            cache[r] = sums[i];
            count += j - k;
            len = r;
        }
        for(int i=0; i<=len; i++)  sums[start+i]=cache[i];
        return count;
    }

    int countRangeSum2(vector<int>& nums, int lower, int upper) {
        int ans = 0;
        int n = nums.size();
        vector<long> sum(n+1, 0);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i-1] + nums[i-1];
        }
        
        multiset<long> m;
        for (int i = 0; i <=n; i++) {
            m.insert(sum[i]);
        }
        
        for (int i = 0; i < n; i++) {
            long l = lower + sum[i];
            long h = upper + sum[i];
            m.erase(m.find(sum[i]));
            auto it_l = m.lower_bound(l);
            auto it_h = m.upper_bound(h);
            int d = distance(it_l, it_h);
            ans += d > 0 ? d : 0;
        }
        return ans;
    }


};
