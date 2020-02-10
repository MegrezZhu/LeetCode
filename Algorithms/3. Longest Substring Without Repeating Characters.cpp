class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int meet[256] = { 0 };
		int ans = 0;
		for (int i = 0, pos = 0; i < s.size(); i++) {
			meet[s[i]]++;
			while (pos < i && meet[s[i]] > 1) meet[s[pos++]]--;
			ans = max(ans, i - pos + 1);
		}
		return ans;
	}
};