class RandomizedCollection {
	unordered_map<int, unordered_set<size_t>> mp;
	vector<int> d;
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {

	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		bool exist = mp.find(val) != mp.end();
		d.push_back(val);
		mp[val].insert(d.size() - 1);
		return !exist;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		auto it = mp.find(val);
		if (it == mp.end()) {
			return false;
		}
		else {
			if (d.back() == val) {
				it->second.erase(d.size() - 1);
				d.pop_back();
			}
			else {
				auto& rpos = *it->second.begin();
				if (rpos != d.size() - 1) {
					auto& sat = mp[d.back()];
					auto pos = d.size() - 1;
					sat.erase(pos);
					sat.insert(rpos);
					swap(d[rpos], d[pos]);
				}
				d.pop_back();
				it->second.erase(rpos);
			}
			if (it->second.empty()) {
				mp.erase(it);
			}
			return true;
		}
	}

	/** Get a random element from the collection. */
	int getRandom() {
		return d[rand() % d.size()];
	}
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */