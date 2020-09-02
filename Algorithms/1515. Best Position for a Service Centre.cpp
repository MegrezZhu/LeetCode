class Solution {
public:
	double getMinDistSum(const vector<vector<int>>& positions) {
		int n = positions.size();
		double lr = 1;

		double x = 0, y = 0;
		int count = 0;
		while (true) {
			count++;
			const auto [gradx, grady] = getGrad(positions, x, y);
			if (norm(gradx, grady) <= 1e-5 || lr <= 1e-7) {
				break;
			}
			x += lr * gradx;
			y += lr * grady;
			lr *= 1 - 1e-4;
		}
		return getDistSum(positions, x, y);
	}
private:
	pair<double, double> getGrad(const vector<vector<int>>& positions, double x, double y) {
		int n = positions.size();
		double gradx = 0, grady = 0;
		for (const auto& p : positions) {
			double deno = norm(p[0] - x, p[1] - y);
			if (deno == 0) continue;
			gradx += -(x - p[0]) / deno;
			grady += -(y - p[1]) / deno;
		}
		return { gradx / n, grady / n };
	}

	double getDistSum(const vector<vector<int>>& positions, double px, double py) {
		double sum = 0;
		for (const auto& p : positions) {
			int x = p[0], y = p[1];
			sum += norm(x - px, y - py);
		}
		return sum;
	}

	double norm(double x, double y) {
		return sqrt(x * x + y * y);
	}
};