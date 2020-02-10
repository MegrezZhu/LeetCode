class AllOne {
	using LevelList = list<pair<int, list<string>>>;
	using LevelListIterator = LevelList::iterator;
	using Level = list<string>;
	using LevelIterator = Level::iterator;

	LevelList levels; // <count, <keys>>
	unordered_map<string, pair<LevelListIterator, LevelIterator>> mp; // may be changed with TRIE
public:
	/** Initialize your data structure here. */
	AllOne() {

	}

	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
	void inc(string key) {
		auto it = mp.find(key);
		if (it == mp.end()) {
			if (levels.empty() || levels.front().first != 1) {
				//auto neo = new list<string>();
				Level neo;
				levels.push_front({ 1, neo });
			}
			auto level = levels.begin();
			level->second.push_front(key);
			mp.insert({ key, {level, level->second.begin()} });
		}
		else {
			auto level = it->second.first;
			auto item = it->second.second;
			level->second.erase(item);

			auto next_level = level;
			next_level++;
			if (next_level == levels.end() || next_level->first != level->first + 1) {
				Level neo;
				next_level = levels.insert(next_level, { level->first + 1, neo });
			}
			next_level->second.push_front(key);
			it->second.first = next_level;
			it->second.second = next_level->second.begin();

			if (level->second.empty()) {
				levels.erase(level);
			}
		}
	}

	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
	void dec(string key) {
		auto it = mp.find(key);
		if (it == mp.end()) {
			// nothing, error occurred
		}
		else {
			auto level = it->second.first;
			auto item = it->second.second;
			level->second.erase(item);

			if (level->first != 1) {
				auto next_level = level;
				if (level == levels.begin()) {
					Level neo;
					next_level = levels.insert(levels.begin(), { level->first - 1, neo });
				}
				else {
					next_level--;
					if (next_level->first != level->first - 1) {
						Level neo;
						next_level = levels.insert(level, { level->first - 1, neo });
					}
				}
				next_level->second.push_front(key);
				it->second.first = next_level;
				it->second.second = next_level->second.begin();

			}
			else {
				mp.erase(it);
			}

			if (level->second.empty()) {
				levels.erase(level);
			}
		}
	}

	/** Returns one of the keys with maximal value. */
	string getMaxKey() {
		if (levels.empty()) return "";
		return levels.back().second.front();
	}

	/** Returns one of the keys with Minimal value. */
	string getMinKey() {
		if (levels.empty()) return "";
		return levels.front().second.front();
	}
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */