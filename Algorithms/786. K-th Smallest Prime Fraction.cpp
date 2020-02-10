class Solution {
public:
	vector<int> kthSmallestPrimeFraction(const vector<int>& A, int K) {
		map<double, pair<int, int>> mp;
		int n = A.size();
		for (int i = 0; i < n - 1; i++) {
			mp.insert({ double(A[i]) / A.back(), {i, n - 1} });
		}
		while (--K) {
			const auto it = mp.begin();
			const auto& p = it->second;
			int l = p.first, r = p.second;
			if (l + 1 < r) {
				mp.insert({ double(A[l]) / A[r - 1], {l, r - 1} });
			}
			mp.erase(it);
		}
		const auto& p = *mp.begin();
		return { A[p.second.first], A[p.second.second] };
	}
};