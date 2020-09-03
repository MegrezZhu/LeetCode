class Solution {
public:
	bool parseBoolExpr(const string &expression) {
		return parse(expression, 0, expression.length() - 1);
	}
private:
	bool parse(const string& expr, int l, int r) {
		if (l == r) {
			if (expr[l] == 't') return true;
			else if (expr[r] == 'f') return false;
			throw invalid_argument(expr.substr(l, r - l + 1));
		}
		if (expr[l] == '(' && expr[r] == ')') {
			return parse(expr, l + 1, r - 1);
		}
		char op = expr[l];
		int parenCount = 0;
		vector<bool> vals;
		for (int i = l + 2, left = l + 2; i <= r; i++) {
			if (parenCount == 0 && (expr[i] == ',' || i == r)) {
				vals.push_back(parse(expr, left, i - 1));
				left = i + 1;
			}
			if (expr[i] == '(') parenCount++;
			else if (expr[i] == ')') parenCount--;
		}
		if (op == '!') return !vals[0];
		auto f = logical_and<bool>();
		if (op == '&') return reduce(vals, logical_and<bool>(), true);
		if (op == '|') return reduce(vals, logical_or<bool>(), false);

        throw invalid_argument(expr.substr(l, r - l + 1));
	}

	template<typename T, typename Y>
	bool reduce(const vector<T>& vals, Y func, T init) {
		auto ret = init;
		for (auto val : vals) ret = func.operator()(ret, val);
		return ret;
	}
};