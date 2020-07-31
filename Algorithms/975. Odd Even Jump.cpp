class Solution {
public:
	int oddEvenJumps(const vector<int>& A) {
		int n = A.size();
		vector<vector<bool>> reachable(2, vector<bool>(n, false));
		reachable[0][n - 1] = reachable[1][n - 1] = true;

		int count = 0;
		map<int, int> mp; // map for odd, for even
		for (int i = n - 1; i >= 0; i--) {
			auto it = mp.lower_bound(A[i]);
			if (it != mp.end()) {
				// odd
				reachable[1][i] = reachable[0][it->second];
			}
			it = mp.upper_bound(A[i]);
			if (it != mp.begin()) {
				// even
				reachable[0][i] = reachable[1][prev(it)->second];
			}

			if (reachable[1][i]) {
				count += 1;
			}
			mp[A[i]] = i;
		}
		return count;
	}
};