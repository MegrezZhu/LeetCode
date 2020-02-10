class Solution {
public:
	int numDistinct(string s, string t) {
		vector<int> f;
		f.resize(t.length() + 1, 0);
		f[0] = 1; // dp[0][0] = 1
		for (int i = 1; i <= s.length(); i++) {
			for (int j = t.length(); j > 0; j--) {
				if (i < j) f[j] = 0;
				else f[j] = f[j] + (s[i - 1] == t[j - 1] ? f[j - 1] : 0);
			}
		}
		return f[t.size()];
	}
};