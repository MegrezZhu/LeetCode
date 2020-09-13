class Solution {
public:
	int unhappyFriends(int n, const vector<vector<int>>& preferences, const vector<vector<int>>& pairs) {
		unordered_map<int, int> pairsMap;
		for (const auto& p : pairs) {
			pairsMap[p[0]] = p[1];
			pairsMap[p[1]] = p[0];
		}
		int count = 0;
		for (const auto& p : pairs) {
			int x = p[0], y = p[1];
			bool unhappy = false;
			for (const auto& q : pairs) {
				int u = q[0], v = q[1];
				if (u == x && v == y) continue;
				if (isUnhappy(preferences, x, y, u, v) || isUnhappy(preferences, x, y, v, u)) {
					count++;
					break;
				}
			}
			for (const auto& q : pairs) {
				int u = q[0], v = q[1];
				if (u == x && v == y) continue;
				if (isUnhappy(preferences, y, x, u, v) || isUnhappy(preferences, y, x, v, u)) {
					count++;
					break;
				}
			}
		}
		return count;
	}
private:
	bool isUnhappy(const vector<vector<int>>& preferences, int x, int y, int u, int v) {
		return findOrder(preferences[u], x) < findOrder(preferences[u], v) && findOrder(preferences[x], u) < findOrder(preferences[x], y);
	}

	int findOrder(const vector<int>& pref, int x) {
		for (int i = 0; i < pref.size(); i++) {
			if (pref[i] == x) return i;
		}
		return -1;
	}
};