class Solution {
public:
	vector<string> braceExpansionII(const string& expr) {
		return parse(expr);
	}
private:
	vector<string> parse(const string& expr) {
		int len = expr.length();
		if (len == 0) return { "" };

		vector<string> splitted; // split by ','
		int paren = 0, left = 0;
		for (int i = 0; i < len; i++) {
			if (expr[i] == '{') paren++;
			if (expr[i] == '}') paren--;
			if (expr[i] == ',' && paren == 0) {
				splitted.push_back(expr.substr(left, i - left));
				left = i + 1;
			}
		}
		if (left < len) {
			splitted.push_back(expr.substr(left, len - left));
		}

		set<string> res;
		for (const auto& sub : splitted) {
			for (const auto& val : parseOne(sub)) {
				res.insert(val);
			}
		}
		return vector<string>(res.begin(), res.end());
	}

	vector<string> parseOne(const string &expr) {
		vector<vector<string>> childs;
		int paren = 0;
		for (int i = 0, left = 0; i < expr.length(); i++) {
			if (expr[i] == '{') paren++;
			else if (expr[i] == '}') {
				if (--paren == 0) {
					childs.push_back(parse(expr.substr(left + 1, i - left - 1)));
					left = i + 1;
				}
			}
			else if (expr[i] >= 'a' && expr[i] <= 'z' && paren == 0) {
				childs.push_back({ expr.substr(i, 1) });
				left = i + 1;
			}
		}

		vector<string> res = { "" };
		for (const auto& child : childs) {
			res = mult(res, child);
		}
		return res;
	}

	vector<string> mult(const vector<string>& va, const vector<string>& vb) {
		set<string> res;
		for (const auto& a : va) {
			for (const auto& b : vb) {
				res.insert(a + b);
			}
		}
		return vector<string>(res.begin(), res.end());
	}
};