// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/#/description
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty())
            return 0;

        int ans = 0;
        int n = prices.size();
        if (k >= prices.size() / 2)
        {
            for (int i = 1; i < n; ++i) {
                if (prices[i] - prices[i - 1] > 0) {
                    ans += prices[i] - prices[i - 1];
                }
            }
        } else {
            vector<vector<int>> local(n, vector<int>(k+1));
            vector<vector<int>> global(n, vector<int>(k+1));
            
            for (int i = 0; i < n-1; ++i) {
                int increase = prices[i+1] - prices[i];
    
                for (int j = 1; j <= k; j++) {
                    local[i+1][j] = max(global[i][j - 1] + max(increase, 0), local[i][j] + increase);
                    global[i+1][j] = max(global[i][j], local[i+1][j]);
                }
            }
            ans = global[n-1][k];
        }
        return ans;        
    }
   
    // Solution 2 
    int maxProfit2(int k, vector<int>& prices) {
        if (prices.empty())
            return 0;

        int ans = 0;
        if (k >= prices.size() / 2)
        {
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] - prices[i - 1] > 0) {
                    ans += prices[i] - prices[i - 1];
                }
            }
        } else {
            vector<int> local(k+1);
            vector<int> global(k+1);
            
            for (int i = 0; i < prices.size() - 1; ++i) {
                int increase = prices[i + 1] - prices[i];
    
                for (int j = k; j >= 1; --j) {
                    local[j] = max(global[j - 1] + max(increase, 0), local[j] + increase);
                    global[j] = max(global[j], local[j]);
                }
            }
            ans = global[k];
        }
        return ans;        
    }
};
