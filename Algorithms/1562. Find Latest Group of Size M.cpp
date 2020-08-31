class Solution {
	vector<int> f; // parent in group, if negative: size of group

	int find(int p) {
		int q = p;
		while (f[q] >= 0) q = f[q];
		while (p != q) {
			int t = f[p];
			f[p] = q;
			p = t;
		}
		return q;
	}

	void unionf(int a, int b) {
		int pa = find(a), pb = find(b);
		if (pa != pb) {
			f[pa] += f[pb];
			f[pb] = pa;
		}
	}
public:
	int findLatestStep(const vector<int>& arr, int m) {
		int n = arr.size();
		unordered_map<int, int> count = {};
		f = vector<int>(n + 1, -1);
		vector<int> state(n + 1, 0);
		int ans = m == 1 ? 0 : -1;
		for (int i = 0; i < arr.size(); i++) {
			state[arr[i]] = 1;
			if (arr[i] > 1 && state[arr[i] - 1] == 1) {
				if (--count[-f[find(arr[i] - 1)]] == 0) {
					count.erase(-f[find(arr[i] - 1)]);
				}
				unionf(arr[i] - 1, arr[i]);
			}
			if (arr[i] + 1 <= n && state[arr[i] + 1] == 1) {
				if (--count[-f[find(arr[i] + 1)]] == 0) {
					count.erase(-f[find(arr[i] + 1)]);
				}
				unionf(arr[i] + 1, arr[i]);
			}
			count[-f[find(arr[i])]]++;
			if (count.find(m) != count.end()) {
				ans = max(ans, i + 1);
			}
		}
		return ans;
	}
};