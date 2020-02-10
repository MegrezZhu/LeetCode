class Solution {
	bool less(const pair<int, int>& a, const pair<int, int>& b) {
		return a.first < b.first && a.second < b.second;
	}
public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		int n = envelopes.size();
		if (!n) return 0;
		sort(envelopes.begin(), envelopes.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
			if (a.first > b.first) return false;
			if (a.first < b.first) return true;
			if (a.second > b.second) return true;
			if (a.second < b.second) return false;
			return false;
		});
		int res = 1;
		vector<int> mx(n + 1, 2e9);
		mx[0] = 0;
		for (int i = 0; i < n; i++) {
			int l = 0, r = n;
			while (l < r) {
				int m = (l + r + 1) / 2;
				int mid = mx[m];
				if (mid < envelopes[i].second) l = m;
				else r = m - 1;
			}

			mx[l + 1] = min(envelopes[i].second, mx[l + 1]);

			res = max(res, l + 1);
		}
		return res;
	}
};