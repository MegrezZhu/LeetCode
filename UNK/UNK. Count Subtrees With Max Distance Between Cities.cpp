class Solution {
	vector<int> ans;
	vector<vector<int>> g;
	int n;
public:
	vector<int> countSubgraphsForEachDiameter(int n, const vector<vector<int>>& edges) {
		ans = vector<int>(n - 1);
		g = vector<vector<int>>(n);
		this->n = n;
		for (const auto& e : edges) {
			g[e[0] - 1].push_back(e[1] - 1);
			g[e[1] - 1].push_back(e[0] - 1);
		}
		vector<bool> tree(n);
		dfs(0, tree);
		return ans;
	}

	void dfs(int L, vector<bool>& tree) {
		if (L == n) {
			int t = maxDist(tree);
			if (t > 0) ans[t - 1]++;
			return;
		}
		tree[L] = true;
		dfs(L + 1, tree);
		tree[L] = false;
		dfs(L + 1, tree);
	}

	int maxDist(const vector<bool>& tree) {
		int first = -1;
		for (int i = 0; i < n; i++) {
			if (tree[i]) {
				first = i;
				break;
			}
		}
		if (first == -1) return 0;
		if (!connected(tree, first)) return 0;
		return get<0>(maxDist(tree, first, -1, 0));
	}

	tuple<int, int> maxDist(const vector<bool>& tree, int root, int parent, int depth) { // max dist in the root tree, max depth
		if (!tree[root]) return { 0, 0 };
		int maxSiblingDepth = 0;
		int ans = 0;
		for (int child : g[root]) {
			if (!tree[child] || child == parent) continue;
			auto [ret, dep] = maxDist(tree, child, root, depth + 1);
			ans = max(ans, ret);
			ans = max(ans, maxSiblingDepth + dep);
			maxSiblingDepth = max(maxSiblingDepth, dep);
		}
		return { ans, maxSiblingDepth + 1 };
	}

	bool connected(const vector<bool>& tree, int root) {
		int size = 0;
		for (bool in : tree) {
			if (in) size++;
		}

		list<int> li = { root };
		vector<bool> visited(n);
		visited[li.front()] = true;

		int count = 1;
		int ret = 0;
		while (!li.empty()) {
			int f = li.front();
			li.pop_front();
			for (int p : g[f]) {
				if (!visited[p] && tree[p]) {
					visited[p] = true;
					count++;
					li.push_back(p);
				}
			}
		}
		return count == size;
	}
};