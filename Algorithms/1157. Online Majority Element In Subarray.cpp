class MajorityChecker {
	unordered_map<int, vector<size_t>> mp;
	vector<int> arr;
public:
	MajorityChecker(vector<int>& arr): arr(arr) {
		for (size_t i = 0; i < arr.size(); i++) {
			mp[arr[i]].push_back(i);
		}
	}

	int query(int left, int right, int threshold) {
		int count = 16;
		while (count--) {
			size_t pos = (rand() % (right - left + 1)) + left;
			int selected = arr[pos];
			if (getCount(selected, left, right) >= threshold) {
				return selected;
			}
		}
		return -1;
	}
private:
	int getCount(int v, size_t l, size_t r) {
		const auto& s = mp[v];
		auto it1 = lower_bound(s.begin(), s.end(), l);
		auto it2 = upper_bound(s.begin(), s.end(), r);
		return it2 - it1;
	}
};