class Solution {
	static string preprocess(const string& s) {
		string res;
		res.resize(s.size() * 2 + 1);
		for (int i = 0; i < res.size(); i++) {
			if (i % 2) res[i] = s[i / 2];
			else res[i] = '#';
		}
		return res;
	}

	static int mirror(int pos, int middle) {
		return 2 * middle - pos;
	}

	static int longestPrefixingPalidrome(const string& s) {
		string ss = preprocess(s);
		vector<int> rl = { 0 };
		int maxRight = 0, pos = 0, ans = 0;

		for (int i = 1; i < ss.length(); i++) {
			int j;
			if (i > maxRight) j = i;
			else {
				// i <= maxRight
				int knownLen = rl[mirror(i, pos)];
				j = min(i + knownLen, maxRight);
			}
			while (j < ss.length() && mirror(j, i) >= 0 && ss[j] == ss[mirror(j, i)]) j++;
			j--;
			rl.push_back(j - i);
			if (j > maxRight) {
				maxRight = j;
				pos = i;
			}
			if (mirror(j, i) == 0) ans = max(ans, rl[i]);
		}

		return ans;
	}
public:
	string shortestPalindrome(string s) {
		int len = longestPrefixingPalidrome(s);
		auto left = s.substr(len);
		reverse(left.begin(), left.end());
		return left + s;
	}
};