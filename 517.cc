https://leetcode.com/problems/super-washing-machines/#/description
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
         if(machines.empty()) return 0;  
        int n = machines.size(), minMv = INT_MIN, avg;  
        vector<int> sum(n+1, 0);  
          
        for(int i=0; i<n; ++i)  
            sum[i+1] = sum[i] + machines[i];  
        if(sum.back() % n) return -1;  
        avg = sum.back() / n;  
          
        for(int i=0; i<n; ++i) {  
            int lCnt = sum[i] - avg * i;  
            int rCnt = sum.back() - sum[i+1] - avg * (n - 1 - i);  
            if(lCnt > 0 && rCnt > 0)  
                minMv = max(minMv, max(lCnt, rCnt));  
            else if(lCnt < 0 && rCnt < 0)  
                minMv = max(minMv, 0 - lCnt - rCnt);  
            else  
                minMv = max(minMv, max(abs(lCnt), abs(rCnt)));  
        }  
          
        return minMv;  
    }

    // Solution 2
    int findMinMoves2(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        if (sum % machines.size() != 0) return -1;
        int res = 0, cnt = 0, avg = sum / machines.size();
        for (int m : machines) {
            cnt += m - avg;
            res = max(res, max(abs(cnt), m - avg));
        }
        return res;
    }
};
