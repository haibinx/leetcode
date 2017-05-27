// https://leetcode.com/problems/split-array-largest-sum/#/description
class Solution {
public:
    int splitArray(const vector<int>& nums, int m) {
        int n = nums.size();
        vector<int>sum(n+1);
        for (int i = 1; i <=n; i++) {
            sum[i] = sum[i-1] + nums[i-1];
        }
        vector<vector<int>> dp(n, vector<int>(m+1, INT_MAX));
        for (int i = 0; i <n; i++) {
            dp[i][1] = sum[n] -sum[i];
        }
        for (int k = 2; k<=m; k++) {
            for (int i = n-k; i >=0; i--) {
                for (int l = i+1; l < n; l++) {
                  dp[i][k] = min(dp[i][k], max(sum[l] - sum[i], dp[l][k-1]));
                }
            }
        }
        return dp[0][m];
    }

    // Solution 2
    int splitArray2(const vector<int>& nums, int m) {
        int n = nums.size();
        vector<int>sum(n+1);
        for (int i = 1; i <=n; i++) {
            sum[i] = sum[i-1] + nums[i-1];
        }
        vector<int> dp(n, INT_MAX);
        for (int i = 0; i <n; i++) {
            dp[i] = sum[n] -sum[i];
        }
        for (int k = 2; k<=m; k++) {
            for (int i = 0; i <= n-k; i++) {
                dp[i] = INT_MAX;
                for (int l = i+1; l < n; l++) {
                  dp[i] = min(dp[i], max(sum[l] - sum[i], dp[l]));
                }
            }
        }
        return dp[0];
    }
    
    // Solution 3
    int splitArray(const vector<int>& nums, int m) {
        long maxNum = 0;
        long sum = 0;
        for (int i : nums) {
            maxNum = max(maxNum, (long)i);
            sum += i;
        }
        return binarySearch(nums, m, maxNum, sum);
    }
    
    int binarySearch(const vector<int>& nums, int m, long low, long high) {
        while (low < high) {
            long mid = low + (high -low) /2;
            if (isValid(nums, m, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
    
    bool isValid(const vector<int>& nums, int m, int maxSum) {
        int cur = 0;
        int count = 1;
        for (int i : nums) {
            cur += i;
            if (cur > maxSum) {
                cur = i;
                count++;
                if (count > m) {
                    return false;
                }
            }
        }
        return true;
    }
};
