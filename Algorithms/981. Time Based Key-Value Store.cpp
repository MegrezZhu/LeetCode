class TimeMap {
    map<string, map<int, string>> mp;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        auto& mp1 = mp[key];
        mp1[timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = mp.find(key);
        if (it == mp.end()) return "";
        const auto& mp1 = it->second;
        auto it1 = mp1.lower_bound(timestamp);
        if (it1->first == timestamp) return it1->second;
        if (it1 == mp1.begin()) return "";
        it1--;
        return it1->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */