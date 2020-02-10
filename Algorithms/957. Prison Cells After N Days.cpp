class Solution {
public:
	vector<int> prisonAfterNDays(vector<int>& cells, int N) {
		int iter = 0;
		vector<int> flags(256, -1);
		flags[convert(cells)] = 0;
		while (iter < N) {
			iter++;
			next(cells);
			int status = convert(cells);
			if (flags[status] != -1) {
				int len = iter - flags[status];
				iter += (N - iter) / len * len;
			}
			else {
				flags[status] = iter;
			}
		}

		return cells;
	}
	int convert(const vector<int> &cells) {
		int res = 0;
		for (int a : cells) res = (res << 1) | a;
		return res;
	}
	void next(vector<int> &cells) {
		int now = convert(cells);
		for (int i = 7, mask = 1; i >= 0; i--) {
			if (i > 0 && i < 7 && !(bool((now & (mask << 1))) ^ bool(now & (mask >> 1)))) cells[i] = 1;
			else cells[i] = 0;
			mask <<= 1;
		}
	}
};