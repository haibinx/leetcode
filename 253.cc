// https://leetcode.com/problems/meeting-rooms-ii
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> mp;
	for (auto& p : intervals) {
	    mp[p.start]++;
	    mp[p.end]--;
	}
	int res = 0, room = 0;
	for (auto& it : mp) {
	  room += it->second;
          res = max(res, room);
        }
	return res;
    }

    // Solution 2
    int minMeetingRooms2(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){
	    return a.start < b.start;
        });
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto a : intervals) {
            if (!q.empty() && q.top() <= a.start) q.pop();
            q.push(a.end);
        }
        return q.size();
    }

    // Solution 3
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts, ends;
        int res = 0, endpos = 0;
        for (auto a : intervals) {
            starts.push_back(a.start);
            ends.push_back(a.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        for (int i = 0; i < intervals.size(); ++i) {
            if (starts[i] < ends[endpos]) ++res;
            else ++endpos;
        }
        return res;
    }
};

