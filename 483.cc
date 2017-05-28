// https://leetcode.com/problems/smallest-good-base/#/description
class Solution {
public:
    typedef unsigned long long ull;
    string smallestGoodBase(string n) {
        ull tn = (ull)stoll(n);
        ull x = 1;
        for (int i = 62; i>= 2; --i) {
            if ( (x << i) < tn) {
                ull cur = helper(tn, i);
                if (cur) return to_string(cur);
            }
        }
        return to_string(tn-1);
    }
    
    ull helper(ull n, int d) {
        double tn = (double) n;
        ull right = (ull) (pow(tn, 1.0/d) + 1);
        ull left=2;
        while (left<=right){
        ull mid=left+(right-left)/2;
        ull sum=1,cur=1;
        for (int i=1;i<=d;i++) {
            cur*=mid;
            sum+=cur;
        }
        if (sum==n) return mid;
        if (sum>n) right=mid-1;
        else left=mid+1;
    }
    return 0;
    }
};
