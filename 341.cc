// https://leetcode.com/problems/flatten-nested-list-iterator/#/description
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto& n : nestedList) {
            flatten(n, data);
        }
        it = data.begin();
    }

    int next() {
        if (hasNext()) {
            return *(it++);
        }
        return 0;
    }

    bool hasNext() {
        return it != data.end();        
    }

private:
    void flatten(NestedInteger& n, vector<int>& data) {
        if (n.isInteger()) {
            data.push_back(n.getInteger());
        } else {
            for (auto& t : n.getList()) {
                flatten(t, data);
            }
        }
    }
    
    vector<int> data;
    vector<int>::iterator it;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
