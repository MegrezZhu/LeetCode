class Solution {
	string make(int l, int r) {
		static char buf[30];
		if (l == r) sprintf(buf, "%d", l);
		else sprintf(buf, "%d->%d", l, r);
		return buf;
	}
public:
	vector<string> summaryRanges(vector<int>& nums) {
		if (nums.empty()) return {};
		vector<string> res;
		int pos = -1;
		for (int i = 0; i < nums.size(); i++) {
			if (i && (long long)nums[i] - nums[i - 1] > 1) {
				res.push_back(make(nums[pos + 1], nums[i - 1]));
				pos = i - 1;
			}
		}
		res.push_back(make(nums[pos + 1], nums.back()));
		return res;
	}
};