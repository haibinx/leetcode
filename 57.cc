// https://leetcode.com/problems/insert-interval/#/description
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        int i = 0;
        while (i < intervals.size() && intervals[i].end < newInterval.start) {
                ans.push_back(intervals[i++]);
        }
        while(i < intervals.size() && intervals[i].start <= newInterval.end){
                newInterval.start =min(intervals[i].start, newInterval.start);
                newInterval.end = max(intervals[i].end, newInterval.end);
                i++;
        }
        ans.push_back(newInterval);
        while(i < intervals.size()) {
            ans.push_back(intervals[i++]);
        }
        return ans;
    }
};
