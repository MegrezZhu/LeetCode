class RandomizedSet {
    unordered_map<int, size_t> mp;
    vector<int> d;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = mp.find(val);
        if (it == mp.end()) {
            d.push_back(val);
            mp[val] = d.size() - 1;
            return true;
        } else {
            return false;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = mp.find(val);
        if (it == mp.end()) {
            return false;
        } else {
            auto &pos = mp[d.back()];
            swap(d[it->second], d[pos]);
            swap(it->second, pos);
            
            d.pop_back();
            mp.erase(it);
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return d[rand() % d.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */