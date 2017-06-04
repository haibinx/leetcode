// https://leetcode.com/problems/find-the-celebrity
class Solution {
public:
    int findCelebrity(int n) {
	vector<bool> candidate(n, true);
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
		if (candidate[i] && i != j) {
		    if (know(i, j) || !know(j, i)) {
			candidate[i] = false;
			break;
		    } else {
			candidate[j] = false;
		    }
 		}
	    }
	    if (candidate[i) return i;
	}
	return -1;
    }

    // Solution 2
    int findCelebrity2(int n) {
	for (int i = 0; i < n; i++) {
	    int j;
	    for (j = 0; j < n; j++) {
		if (i != j && (know(i, j) || !know(j, i))) break;
            }
            if (j == n) return i;
        }
	return -1;
    }

    // Solution 3
    int findCelebrity3(int n) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (knows(res, i)) res = i;
        }
        for (int i = 0; i < n; ++i) {
            if (res != i && (knows(res, i) || !knows(i, res))) return -1;
        }
        return res;
    }
};
