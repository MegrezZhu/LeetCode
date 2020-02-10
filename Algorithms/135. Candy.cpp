class Solution {
	vector<int> res;
	vector<int> ratings;
	int calculate(int pos) {
		if (pos < 0 || pos >= res.size()) return 0;
		if (res[pos] != -1) return res[pos];
		int left = get(pos - 1) < get(pos) ? calculate(pos - 1) : 0;
		int right = get(pos + 1) < get(pos) ? calculate(pos + 1) : 0;
		return res[pos] = max(left, right) + 1;
	}
	int get(int pos) {
		return (pos < 0 || pos >= ratings.size()) ? 1e9 : ratings[pos];
	}
public:
	int candy(vector<int>& ratings) {
		this->ratings = ratings;
		res.clear();
		res.resize(ratings.size(), -1);
		int ans = 0;
		for (int i = 0; i < res.size(); i++) ans += calculate(i);
		return ans;
	}
};