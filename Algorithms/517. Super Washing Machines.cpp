class Solution {
public:
	int findMinMoves(vector<int>& machines) {
		int sum = 0, n = machines.size();
		for (int v : machines) sum += v;
		if (sum % n) return -1;
		int target = sum / n;

		vector<vector<int>> in(n), out(n);
		int p = 0, last = 0;
		int ans = 0;
		while (p < n) {
			while (last < n && machines[last] >= target) last++;
			if (last >= n) break;
			if (machines[p] <= target) {
				p++;
			}
			else {
				int pack = min(target - machines[last], machines[p] - target);
				ans = max(ans, machines[p] - target);
				machines[p] -= pack;
				machines[last] += pack;
				int left = min(p, last), right = max(p, last);
				int mod = p < last ? +1 : -1;
				in[left].push_back(mod * pack);
				out[right].push_back(mod * pack);
			}
		}

		for (int i = 0, val = 0; i < n - 1; i++) {
			for (int v : in[i]) val += v;
			ans = max(ans, abs(val));
			for (int v : out[i]) val -= v;
		}
		return ans;
	}
};