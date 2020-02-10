class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";
		for (int pos = 0; pos <= strs.front().length(); pos++) {
			for (const string& s : strs) {
				if (pos >= s.length() || s[pos] != strs.front()[pos]) return strs.front().substr(0, pos);
			}
		}
	}
};