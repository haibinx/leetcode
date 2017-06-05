// https://leetcode.com/problems/gas-station/#/description
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, cur = 0, start = 0, n = gas.size();
        for (int i = 0; i < n; i++) {
            int left = gas[i] - cost[i];
            total += left;
            cur += left;
            if (cur < 0) {
                cur = 0;
                start = i+1;
            }
        }
        return (total >= 0) ? start : -1;
    }
};
