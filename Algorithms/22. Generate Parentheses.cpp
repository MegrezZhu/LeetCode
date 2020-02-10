class Solution {
	void gen(vector<string> &res, int a, int b, int left = 0, string now = "") {
		if (!left && !a && !b) res.push_back(now);
		if (a) gen(res, a - 1, b, left + 1, now + '(');
		if (b && left) gen(res, a, b - 1, left - 1, now + ')');
	}
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		gen(result, n, n);
		return result;
	}
};