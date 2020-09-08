class Solution {
public:
	int expressiveWords(const string& S, const vector<string>& words) {
		int count = 0;
		for (const auto& w : words) {
			if (isStretch(S, w)) count++;
		}
		return count;
	}
private:
	bool isStretch(const string& S, const string& w) {
		int p = 0, q = 0;
		while (p < S.length() && q < w.length()) {
			if (S[p] != w[q]) return false;
			int p1 = p, q1 = q;
			while (p1 + 1 < S.length() && S[p] == S[p1 + 1]) p1++;
			while (q1 + 1 < w.length() && w[q] == w[q1 + 1]) q1++;
			int len1 = p1 - p + 1, len2 = q1 - q + 1;
			if (len1 < len2 || len1 != len2 && len1 < 3) return false;
			p = p1 + 1;
			q = q1 + 1;
		}
		return p == S.length() && q == w.length();
	}
};