class Solution {
public:
	vector<int> pancakeSort(vector<int>& A) {
		vector<int> res;
		int n = A.size();
		for (int i = 0; i < n; i++) {
			int maxx = -1e9, pos;
			for (int j = 0; j < n - i; j++) {
				if (A[j] >= maxx) {
					maxx = A[j];
					pos = j;
				}
			}
			res.push_back(pos + 1);
			reverse(A.begin(), A.begin() + pos + 1);
			res.push_back(n - i);
			reverse(A.begin(), A.begin() + n - i);
		}
		return res;
	}
};