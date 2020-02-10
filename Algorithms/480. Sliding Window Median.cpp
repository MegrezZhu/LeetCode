class Solution {
public:
	vector<double> medianSlidingWindow(const vector<int>& nums, int k) {
		multiset<int, greater<int>> left(nums.begin(), nums.begin() + k - 1);
		multiset<int> right;
		vector<double> res;
		for (int i = k - 1; i < nums.size(); i++) {
			if (right.empty() || nums[i] <= *right.begin()) {
				left.insert(nums[i]);
			}
			else {
				right.insert(nums[i]);
			}

			while (left.size() > (k + 1) / 2) {
				right.insert(*left.begin());
				left.erase(left.begin());
			}
			while (right.size() > k / 2) {
				left.insert(*right.begin());
				right.erase(right.begin());
			}
			if (k % 2) res.push_back(*left.begin());
			else res.push_back((double(*left.begin()) + *right.begin()) / 2.);
			int last = i - k + 1;
			auto it = left.find(nums[last]);
			if (it != left.end()) {
				left.erase(it);
			}
			else {
				right.erase(right.find(nums[last]));
			}
		}
		return res;
	}
};