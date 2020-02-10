class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int n = intervals.size();
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++) {
			v[i].first = intervals[i][0];
			v[i].second = intervals[i][1];
		}
		sort(v.begin(), v.end());
		vector<vector<int>> ans;
		int l = -1, r = 0;
		for (const auto &p : v) {
			if (l == -1) {
				l = p.first;
				r = p.second;
			}
			else {
				if (p.first <= r) {
					r = max(r, p.second);
				}
				else {
					ans.push_back({ l, r });
					l = p.first;
					r = p.second;
				}
			}
		}
		if (l != -1) ans.push_back({ l, r });
		return ans;
	}
};