class Solution {
public:
	vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
		vector<vector<int>> e(N);
		for (const auto &edge : paths) {
			e[edge[0] - 1].push_back(edge[1] - 1);
			e[edge[1] - 1].push_back(edge[0] - 1);
		}
		vector<int> state(N, -1);
		vector<vector<int>> choice(N, vector<int>(4, 0));
		vector<int> ans;
		dfs(0, e, state, choice, ans);
		return ans;
	}
	bool dfs(int L, const vector<vector<int>> &e, vector<int> &state, vector<vector<int>> &choice, vector<int> &ans) {
		if (L >= e.size()) {
			ans = move(state);
			return true;
		}
		for (int i = 0; i < 4; i++) {
			if (choice[L][i] == 0) {
				state[L] = i + 1;
				for (int adj : e[L]) {
					choice[adj][i]++;
				}
				bool res = dfs(L + 1, e, state, choice, ans);
				if (res) return true;
				for (int adj : e[L]) {
					choice[adj][i]--;
				}
			}
		}
		return false;
	}
};