class Solution {
public:
	int largestRectangleArea(const vector<int>& heights) {
		int n = heights.size();
		stack<pair<int, int>> s; // <left pos, height>
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int left = i;
			while (!s.empty() && heights[i] <= s.top().second) {
				ans = max(ans, s.top().second * (i - s.top().first));
				left = s.top().first;
				s.pop();
			}
			s.push({ left, heights[i] });
		}
		while (!s.empty()) {
			ans = max(ans, s.top().second * (n - s.top().first));
			s.pop();
		}
		return ans;
	}
};