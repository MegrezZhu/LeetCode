class Solution {
	vector<vector<int>> m; // m[i][j] -> min of range [i, i+2^j-1]
public:
	int maxJumps(const vector<int>& arr, int d) {
		int n = arr.size(), ans = 1;

		if (n == 1) {
			return 1;
		}

		vector<int> ids(n);
		for (int i = 0; i < n; i++) {
			ids[i] = i;
		}
		sort(ids.begin(), ids.end(), [&](int a, int b) { return arr[a] < arr[b]; });
		initRangeMin(arr);
		vector<int> f(n, -1);
		for (int id : ids) {
			f[id] = 1;
			for (int i = 1; i <= d && id - i >= 0; i++) {
				if (rangeMin(id - i, id - 1) < arr[id]) {
					f[id] = max(f[id], f[id - i] + 1);
				}
				else {
					break;
				}
			}
			for (int i = 1; i <= d && id + i < n; i++) {
				if (rangeMin(id + 1, id + i) < arr[id]) {
					f[id] = max(f[id], f[id + i] + 1);
				}
				else {
					break;
				}
			}
			ans = max(ans, f[id]);
		}

		return ans;
	}

	void initRangeMin(const vector<int>& arr) {
		int n = arr.size();
		int d = floor(log(n) / log(2)) + 1;
		m = vector<vector<int>>(n, vector<int>(d, 0));
		for (int i = 0; i < n; i++) {
			m[i][0] = arr[i];
		}
		int step = 1;
		for (int j = 1; j < d; j++) {
			for (int i = 0; i < n; i++) {
				m[i][j] = m[i][j - 1];
				if (i + step < n) {
					m[i][j] = max(m[i][j], m[i + step][j - 1]);
				}
			}
			step *= 2;
		}
	}

	int rangeMin(int l, int r) {
		int len = r - l + 1;
		int d = floor(log(len) / log(2));
		return max(m[l][d], m[r - pow(2, d) + 1][d]);
	}
};