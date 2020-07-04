class Solution {
public:
	bool isPossibleDivide(const vector<int>& nums, int k) {
		if (nums.size() % k != 0) {
			return false;
		}
		map<int, int> mp;
		for (int x : nums) mp[x]++;
		while (!mp.empty()) {
			auto it = mp.begin();
			int count = it->second;

			auto it1 = it;
			for (int i = 0; i < k - 1; i++) {
				it1 = next(it1);
				if (it1 == mp.end() || it1->first != it->first + i + 1) {
					return false;
				}
				count = min(count, it1->second);
			}

			it1 = it;
			for (int i = 0; i < k; i++) {
				auto it2 = next(it1);

				it1->second -= count;
				if (it1->second == 0) {
					mp.erase(it1);
				}

				it1 = it2;
			}
		}

		return true;
	}
};