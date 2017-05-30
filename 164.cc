// https://leetcode.com/problems/maximum-gap/#/description
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int maxV = INT_MIN, minV = INT_MAX;
        for (int i : nums) {
            maxV = max(maxV, i);
            minV = min(minV, i);
        }
        int sSize = nums.size();
        int bucket_size = max(1, (maxV - minV )/ (sSize - 1));
        int bucket_num  = (maxV - minV)/bucket_size + 1;
        if(bucket_num <=1) return (maxV - minV);
        vector<pair<int, int>> buckets(bucket_num, make_pair(INT_MAX, INT_MIN));
        
        for (int i : nums) {
            int bucket_id = (i - minV)/bucket_size;
            auto& p = buckets[bucket_id];
            if (i < p.first) p.first = i;
            if (i > p.second) p.second = i;
        }
        
        int maxGap = INT_MIN;
        int last_max = minV;
        for(int i=0; i<bucket_num; i++) {
            if(buckets[i].first != INT_MAX || buckets[i].second != INT_MIN) {
                maxGap = max(maxGap, buckets[i].first - last_max);
                last_max = buckets[i].second;
            }
        }
        return maxGap;
    }
};
