class Solution {
	bool match(char a, char b) {
		return a == '(' && b == ')';
	}
public:
	int longestValidParentheses(string s) {
		stack<pair<char, int>> stk;
		int ans = 0;
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			if (stk.empty() || !match(stk.top().first, c)) stk.push(make_pair(c, i));
			else {
				stk.pop();
				int left = stk.empty() ? -1 : stk.top().second;
				ans = max(ans, i - left);
			}
		}
		return ans;
	}
};