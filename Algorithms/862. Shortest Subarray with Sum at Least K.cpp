class Solution {
public:
	int shortestSubarray(const vector<int>& A, int K) {
		int n = A.size();

		vector<int> preSum(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			preSum[i] = preSum[i - 1] + A[i - 1];
		}

		list<int> nonPosLoc;
		int ans = n + 1, left = 0, maxSum = -1e9;
		for (int i = 0; i < A.size(); i++) {
			while (left < i) { // trimming
				int sum = rangeSum(preSum, left, i);
				if (A[left] <= 0) {
					if (nonPosLoc.front() == left) {
						nonPosLoc.pop_front();
					}
					left++;
				}
				else if (sum - A[left] >= K) {
					left++;
				}
				else if (!nonPosLoc.empty() && sum - rangeSum(preSum, left, nonPosLoc.front()) >= K) {
					left = nonPosLoc.front() + 1;
					nonPosLoc.pop_front();
				}
				else {
					break;
				}
			}
			if (A[i] <= 0) {
				if (!nonPosLoc.empty() && nonPosLoc.back() == i - 1) {
					nonPosLoc.pop_back();
				}
				while (!nonPosLoc.empty() && rangeSum(preSum, left, nonPosLoc.back()) >= rangeSum(preSum, left, i)) {
					nonPosLoc.pop_back();
				}
				nonPosLoc.push_back(i);
			}
			if (rangeSum(preSum, left, i) >= K) {
				ans = min(ans, i - left + 1);
			}
		}

		if (ans != n + 1) {
			return ans;
		}
		else {
			return -1;
		}
	}
private:
	int rangeSum(const vector<int>& preSum, int l, int r) { // inclusive
		return preSum[r + 1] - preSum[l];
	}
};