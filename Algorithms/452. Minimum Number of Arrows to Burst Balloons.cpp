class Solution {
public:
	int findMinArrowShots(vector<pair<int, int>>& points) {
		int result = 0;
		sort(points.begin(), points.end(), [](pair<int, int> a, pair<int, int> b) {
			if (a.first < b.first) return true;
			if (a.first > b.first) return false;
			if (a.second < b.second) return true;
			if (a.second > b.second) return false;
			return false;
		});

		priority_queue<int, vector<int>, greater<int>> q;
		for (const auto &p : points) {
			if (!q.empty() && q.top() < p.first) {
				result++;
				while (!q.empty()) q.pop();
			}
			q.push(p.second);
		}

		if (!q.empty()) result++;
		return result;
	}
};