class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(N+2, vector<int>(N+2, 0));
        //dp[i][j] means max coins got from i to j
        //dp[i][j] = max(dp[i][j], dp[i][x-1] + nums[i-1]*nums[x]*nums[j+1] + dp[x+1][j])
        for (int len = 1; len <= N; ++len) {
            for (int start = 1; start <= N-len+1; ++start) {
                int end = start + len - 1;
                for (int x = start; x <= end; x++) {
                    dp[start][end] = max(dp[start][end], dp[start][x-1] + nums[start-1]*nums[x]*nums[end+1] + dp[x+1][end]);
                }
            }
        }
        return dp[1][N];
    }
};
