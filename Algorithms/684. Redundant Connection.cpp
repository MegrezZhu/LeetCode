class Solution {
	int find(vector<int>& parent, int p) {
		int fa = p;
		while (parent[fa] != -1) fa = parent[fa];
		while (p != fa) {
			int tmp = parent[p];
			parent[p] = fa;
			p = tmp;
		}
		return fa;
	}

	bool unite(vector<int> &parent, int a, int b) {
		int pa = find(parent, a), pb = find(parent, b);
		if (pa != pb) {
			parent[pb] = pa;
			return true;
		}
		return false;
	}
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		int n = edges.size();
		vector<int> parent(n, -1);
		for (auto& edge : edges) {
			if (!unite(parent, edge[0] - 1, edge[1] - 1)) return edge;
		}
	}
};