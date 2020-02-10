class Solution {
public:
	double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
		int n = A.size(), m = B.size();
		int s = n + m;
		if (s % 2) return findIth(A, B, 0, n - 1, 0, m - 1, s / 2);
		else return (findIth(A, B, 0, n - 1, 0, m - 1, s / 2 - 1) + findIth(A, B, 0, n - 1, 0, m - 1, s / 2)) / 2.;
	}
	double findIth(const vector<int>& A, const vector<int>& B, int la, int ra, int lb, int rb, int p) {
		if (la > ra) return B[lb + p];
		if (lb > rb) return A[la + p];
		int n = (ra - la + 1) + (rb - lb + 1);
		int mida = (la + ra) / 2, midb = (lb + rb) / 2;
		int L = (mida - la + 1) + (midb - lb + 1) - 1, R = (ra - mida + 1) + (rb - midb + 1) - 1;
		if (A[mida] <= B[midb]) {
			int p0 = p;
			if (p0 > n - R - 1) {
				p -= mida - la + 1;
				la = mida + 1;
			}
			if (p0 < L) {
				rb = midb - 1;
			}
			return findIth(A, B, la, ra, lb, rb, p);
		}
		else {
			int p0 = p;
			if (p0 > n - R - 1) {
				p -= midb - lb + 1;
				lb = midb + 1;
			}
			if (p0 < L) {
				ra = mida - 1;
			}
			return findIth(A, B, la, ra, lb, rb, p);
		}
	}
};