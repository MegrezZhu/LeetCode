class Solution {
public:
	vector<int> findOrder(int n, vector<pair<int, int>>& edges) {
		vector<list<int>> d(n);
		vector<int> in(n, 0);
		for (const auto& e : edges) {
			d[e.second].push_back(e.first);
			in[e.first]++;
		}
		vector<int> res;
		list<int> li;
		for (int i = 0; i < n; i++) {
			if (in[i] == 0) li.push_back(i);
		}
		while (!li.empty()) {
			int node = li.front();
			li.pop_front();
			res.push_back(node);
			for (int p : d[node]) {
				in[p]--;
				if (in[p] == 0) li.push_back(p);
			}
		}
		return res.size() == n ? res : vector<int>();
	}
};