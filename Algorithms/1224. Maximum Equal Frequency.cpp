class Solution {
public:
	int maxEqualFreq(const vector<int>& nums) {
		list<pair<int, list<int>>> levels; // <count, val>
		unordered_map<int, pair<list<pair<int, list<int>>>::iterator, list<int>::iterator>> mp; // val -> position in levels
		int ans = 1;
		for (int i = 0; i < nums.size(); i++) {
			int x = nums[i];
			if (mp.find(x) == mp.end()) {
				if (levels.empty() || levels.front().first != 1) {
					levels.push_front({ 1, list<int>() });
				}
				levels.front().second.push_front(x);
				mp[x] = { levels.begin(), levels.front().second.begin() };
			}
			else {
				auto p = mp[x];
				auto level = p.first;
				auto it = p.second;

				auto nextLevel = next(level);
				if (nextLevel == levels.end() || nextLevel->first != level->first + 1) {
					nextLevel = levels.insert(nextLevel, { level->first + 1, list<int>() });
				}

				level->second.erase(it);
				if (level->second.empty()) {
					levels.erase(level);
				}

				nextLevel->second.push_front(x);
				mp[x] = { nextLevel, nextLevel->second.begin() };
			}
			
			if (levels.size() == 2) {
				const auto& level1 = levels.front();
				const auto& level2 = levels.back();
				if (level1.first == 1 && level1.second.size() == 1 ||
						level2.first == level1.first + 1 && level2.second.size() == 1) {
					ans = max(ans, i + 1);
				}
			}
			else if (levels.size() == 1) {
				if (levels.front().first == 1 || levels.front().second.size() == 1)
				ans = max(ans, i + 1);
			}
		}
		return ans;
	}
};
