class Solution {
	using Frac = pair<int, int>;
public:
	int maxPoints(vector<vector<int>>& points) {
		if (points.empty()) return 0;
		int n = points.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			map<Frac, int> mp;
			int inf = 0;
			int same = 1;
			const auto& p1 = points[i];
			for (int j = 0; j < n; j++) {
				const auto& p2 = points[j];
				if (j == i) continue;
				if (p1[0] == p2[0] && p1[1] == p2[1]) same++;
				else if (p1[0] == p2[0]) inf++;
				else mp[slope(p1[0], p1[1], p2[0], p2[1])]++;
			}
			ans = max(ans, inf + same);
			for (const auto& p : mp) {
				ans = max(ans, p.second + same);
			}
		}
		return ans;
	}
private:
	Frac slope(int x0, int y0, int x1, int y1) {
		static const double DIGIT = 1e6;
		int a = y1 - y0, b = x1 - x0;
		int g = gcd(a, b);
		return { a / g, b / g };
	}
	int gcd(int a, int b) {
		int r = a % b;
		if (r == 0) return b;
		return gcd(b, r);
	}
};