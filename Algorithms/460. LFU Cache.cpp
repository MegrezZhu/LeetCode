class LFUCache {
	using LevelList = list<pair<int, list<int>>>;
	LevelList levels; // <count, [key]>
	unordered_map<int, pair<LevelList::iterator, list<int>::iterator>> kl; // <key, <level, in-level iter> >
	unordered_map<int, int> kv; // <key, val>
	int cap;

public:
	LFUCache(int capacity) : cap(capacity) {

	}

	int get(int key) {
		auto it = kv.find(key);
		if (it == kv.end()) return -1;

		const auto &p = kl[key];
		auto level = p.first;
		auto iter = p.second;
		int count = level->first;
		auto& li = level->second;

		li.erase(iter);
		auto nextLevel = next(level);
		if (nextLevel == levels.end() || nextLevel->first != count + 1) {
			nextLevel = levels.insert(nextLevel, { count + 1, {} });
		}
		nextLevel->second.push_back(key);
		kl[key] = { nextLevel, prev(nextLevel->second.end()) };

		if (li.size() == 0) {
			levels.erase(level);
		}

		return kv[key];
	}

	void put(int key, int value) {
		if (cap == 0) return;

		auto it = kv.find(key);
		if (it != kv.end()) {
			kv[key] = value;
			get(key); // update count
		}
		else {
			if (kv.size() == cap) {
				auto firstLevel = levels.begin();
				auto& li = firstLevel->second;
				int rmKey = li.front();
				kv.erase(rmKey);
				kl.erase(rmKey);
				li.pop_front();
				if (li.size() == 0) {
					levels.pop_front();
				}
			}

			kv[key] = value;
			if (levels.empty() || levels.front().first != 0) {
				levels.push_front({ 0, {} });
			}
			levels.front().second.push_back(key);
			kl[key] = { levels.begin(), prev(levels.front().second.end()) };
		}
	}
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */