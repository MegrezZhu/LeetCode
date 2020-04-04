class Solution {
public:
	int getKth(int lo, int hi, int k) {
		unordered_map<int, int> mp = { {1, 0} };

		vector<pair<int, int>> res;
		for (int i = lo; i <= hi; i++) {
			res.push_back({ i, pow(i, mp) });
		}
		sort(res.begin(), res.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
			if (a.second < b.second) return true;
			else if (a.second == b.second) return a.first < b.first;
			else return false;
		});

		return res[k - 1].first;
	}

	int pow(int x, unordered_map<int, int>& cache) {
		auto it = cache.find(x);
		if (it != cache.end()) return it->second;

		int val;
		if (x % 2 == 0) val = pow(x / 2, cache);
		else val = pow(3 * x + 1, cache);

		cache[x] = val + 1;
		return val + 1;
	}
};