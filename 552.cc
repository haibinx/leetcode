// https://leetcode.com/problems/student-attendance-record-ii/#/description
class Solution {
public:
    int checkRecord(int n) {
       // dp_i_j means the rewardable number which contains i 'A's and ends with j 'L's.
       long dp_0_0 = 1;
       long dp_1_0 = 1;
       long dp_0_1 = 1;
       long dp_1_1 = 0;
       long dp_0_2 = 0;
       long dp_1_2 = 0;
       long mod = 1000000007;
       for (int i = 2; i <= n; i++) {
           long new_dp_0_0 = (dp_0_0  + dp_0_1  + dp_0_2) % mod;
           long new_dp_1_0 = (dp_0_0 + dp_1_0 + dp_0_1 + dp_1_1 + dp_0_2 + dp_1_2) % mod;
           long new_dp_0_1 = dp_0_0;
           long new_dp_1_1 = dp_1_0;
           long new_dp_0_2 = dp_0_1;
           long new_dp_1_2 = dp_1_1;
           dp_0_0 = new_dp_0_0;
           dp_1_0 = new_dp_1_0;
           dp_0_1 = new_dp_0_1;
           dp_1_1 = new_dp_1_1;
           dp_0_2 = new_dp_0_2;
           dp_1_2 = new_dp_1_2;
       }
       return (dp_0_0 + dp_0_1 + dp_1_0 + dp_1_1 + dp_0_2 + dp_1_2) % mod;
    }
};
