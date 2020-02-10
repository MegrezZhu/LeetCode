class Solution {
public:
	int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
		int n = Profits.size();
		vector<pair<int, int>> cp(n); // <capital, profit>
		for (int i = 0; i < n; i++) cp[i] = { Capital[i], Profits[i] };
		sort(cp.begin(), cp.end());
		priority_queue<int> q;
		auto it = cp.begin();
		int val = W;
		while (k--) {
			while (it != cp.end() && it->first <= val) {
				q.push(it->second);
				it++;
			}
			if (q.empty()) break;
			val += q.top();
			q.pop();
		}
		return val;
	}
};