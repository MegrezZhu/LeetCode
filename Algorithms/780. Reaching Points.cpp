class Solution {
public:
	bool reachingPoints(int sx, int sy, int tx, int ty) {
		if (sx == tx && sy == ty) return true;
		if (sx > tx || sy > ty) return false;
		if (tx == ty) return false;
		if (tx < ty) {
			return reachingPoints(sx, sy, tx, min((ty - sy) % tx + sy, ty - tx));
		}
		else {
			return reachingPoints(sx, sy, min((tx - sx) % ty + sx, tx - ty), ty);
		}
	}
};