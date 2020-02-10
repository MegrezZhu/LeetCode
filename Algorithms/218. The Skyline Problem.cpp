class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		map<int, vector<pair<int, bool>>> mp;

		for (const auto& building : buildings) {
			mp[building[0]].push_back({ building[2],true });
			mp[building[1]].push_back({ building[2],false });
		}

		map<int, int> tops;
		vector<pair<int, int>> result;
		for (const auto& vert : mp) {
			for (const auto &p : vert.second) {
				if (p.second) tops[p.first]++; // adding
				else {
					tops[p.first]--;
					if (tops[p.first] == 0) tops.erase(p.first);
				}
			}
			pair<int, int> key = { vert.first, tops.rbegin() != tops.rend() ? tops.rbegin()->first : 0 };
			if (result.empty() || result.back().second != key.second) result.push_back(key);
		}

		return result;
	}
};