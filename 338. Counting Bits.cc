// https://leetcode.com/problems/counting-bits/#/description
class Solution {
public:
    /*vector<int> countBits(int num) {
        if (num == 0) return {0};
        vector<int> res({0, 1});
        int k = 1, i = 2;
        while (i <= num) {
            for (i = pow(2, k); i < pow(2, k+1); i++) {
                if (i > num) break;
                int t = (pow(2, k+1) - pow(2, k)) / 2;
                if (i < pow(2, k) + t) res.push_back(res[i -t]);
                else res.push_back(res[i-t] + 1);
            }
            k++;
        }
        return res;
    }*/
    
    vector<int> countBits(int num) {
        vector<int> res{0};
        for (int i = 1; i <= num; ++i) {
            if (i % 2 == 0) res.push_back(res[i / 2]);
            else res.push_back(res[i / 2] + 1);
        }
        return res;
    }
    
    /*vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for (int i = 1; i <= num; ++i) {
            res[i] = res[i & (i - 1)] + 1;
        }
        return res;
    }*/
};
