class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
		int n = pairs.size(), ans = 1;
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++) {
			v[i].first = pairs[i][0];
			v[i].second = pairs[i][1];
		}
		sort(v.begin(), v.end());

		vector<int> f(n + 1, 1e9);
		for (int i = 0; i < n; i++) {
			f[1] = min(f[1], v[i].second);
			for (int j = i; j >= 0; j--) {
				if (f[j] < v[i].first) {
					f[j + 1] = min(f[j + 1], v[i].second);
					ans = max(ans, j + 1);
					break;
				}
			}
		}

		return ans;
	}
};