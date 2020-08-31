class Solution {
public:
	double mincostToHireWorkers(const vector<int>& quality, const vector<int>& wage, int K) {
		int n = quality.size();
		vector<int> ids;
		for (int i = 0; i < n; i++) ids.push_back(i);
		sort(ids.begin(), ids.end(), [&](int a, int b) { // sort by w/q
			return double(wage[a]) / quality[a] < double(wage[b]) / quality[b];
			});

		map<int, int> mp; // q -> count, with K-1 minimal q
		double sumQ = 0, ans = 1e9;
		for (int i = 0; i < n; i++) {
			int id = ids[i];
			if (i >= K - 1) {
				double factor = double(wage[id]) / quality[id];
				ans = min(ans, factor * (quality[id] + sumQ));
			}
			if (K > 1) {
				if (i >= K - 1) {
					if (quality[id] < mp.rbegin()->first) {
						auto it = prev(mp.end());
						int maxQ = it->first;
						if (--it->second == 0) {
							mp.erase(it);
						}
						mp[quality[id]]++;
						sumQ += quality[id] - maxQ;
					}
				}
				else {
					mp[quality[id]]++;
					sumQ += quality[id];
				}
			}
		}
		return ans;
	}
};