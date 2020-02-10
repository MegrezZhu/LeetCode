class Solution {
	typedef long long ll;
	bool check(const vector<int> &nums, int m, int limit) {
		for (int i = 0, sum = 0; i < nums.size(); i++) {
			if (sum + nums[i] <= limit) sum += nums[i];
			else {
				m--;
				if (m == 0) return false;
				sum = nums[i];
			}
		}
		return true;
	}
public:
	int splitArray(vector<int>& nums, int m) {
		int n = nums.size();
		int l = 0, r = 0;
		for (int i : nums) {
			l = max(l, i);
			r += i;
		}
		int ans = 2147483647;
		while (l <= r) {
			int mid = (ll(l) + ll(r)) / 2;
			if (check(nums, m, mid)) {
				r = mid - 1;
				ans = min(ans, mid);
			}
			else l = mid + 1;
		}
		return ans;
	}
};