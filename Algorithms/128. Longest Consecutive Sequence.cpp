class Solution {
	void updateMax(unordered_map<int, int> &mp, int pos, int val) {
		auto it = mp.find(pos);
		if (it == mp.end()) mp.insert(make_pair(pos, val));
		else it->second = max(it->second, val);
	}

	void updateMin(unordered_map<int, int> &mp, int pos, int val) {
		auto it = mp.find(pos);
		if (it == mp.end()) mp.insert(make_pair(pos, val));
		else it->second = min(it->second, val);
	}
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> left, right; // left: started a x, leftmost pos
		int ans = 0;
		for (int a : nums) {
			int l = a, r = a;
			auto itl = left.find(a - 1);
			if (itl != left.end()) l = itl->second;
			auto itr = right.find(a + 1);
			if (itr != right.end()) r = itr->second;

			updateMax(right, l, r);
			updateMin(left, r, l);

			ans = max(ans, r - l + 1);
		}
		return ans;
	}
};