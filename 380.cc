// https://leetcode.com/problems/insert-delete-getrandom-o1/#/description
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool ret = mp.find(val) == mp.end();
        if (ret) {
            mp[val] = data.size();
            data.push_back(val);
        }
        return ret;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool ret = mp.find(val) != mp.end();
        if (ret) {
            int last = data.back();
            data[mp[val]] = last;
            mp[last] = mp[val];
            data.pop_back();
            mp.erase(val);
        }
        return ret;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return data[rand() % data.size()];
    }
private:
    vector<int> data;
    unordered_map<int, int> mp;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
