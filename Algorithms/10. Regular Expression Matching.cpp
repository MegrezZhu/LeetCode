class Solution {
public:
	bool isMatch(string ss, string pp) {
		s = ' ' + ss;
		p = ' ' + pp;
		res.resize(s.size());
		calculated.resize(s.size());
		for (int i = 0; i < s.size(); i++) {
			res[i].clear();
			res[i].resize(p.size(), false);
			calculated[i].clear();
			calculated[i].resize(p.size(), false);
		}

		match(0, 0);
		return res[s.size() - 1][p.size() - 1];
	}

	void match(int i, int j) {
		if (i >= s.size() || j >= p.size()) return;
		if (calculated[i][j]) return;
		res[i][j] = calculated[i][j] = true;

		if (j < p.size() - 1) { // reg remaining
			bool starMatch = false;
			if (j < p.size() - 2 && p[j + 2] == '*') starMatch = true;
			if (i < s.size() - 1) {
				char toMatch = p[j + 1];
				bool anyMatch = toMatch == '.';
				if (starMatch) {
					int k = i;
					while (k < s.size()) {
						match(k, j + 2);
						if (k < s.size() - 1 && (anyMatch || s[k + 1] == toMatch)) k++;
						else break;
					}
				}
				else {
					if (anyMatch || s[i + 1] == toMatch) match(i + 1, j + 1);
				}
			}
			else {
				if (starMatch) match(i, j + 2);
			}
		}
	}

private:
	string s, p;
	vector<vector<bool>> res, calculated;
};