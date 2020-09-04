class SummaryRanges {
	using Intervals = list<pair<int, int>>;

	Intervals intervals; // in ascending order
	set<int> s; // set of vals
	unordered_map<int, int> parent;
	unordered_map<int, Intervals::iterator> idToInterval;
public:
	/** Initialize your data structure here. */
	SummaryRanges() {

	}

	void addNum(int val) {
		if (s.find(val) != s.end()) return;

		auto it = s.lower_bound(val);
		if (it == s.begin()) {
			intervals.push_front({ val, val });
			idToInterval[val] = intervals.begin();
		}
		else {
			int val1 = *prev(it); // greatest one that is smaller than val
			auto intervalIt = idToInterval[findGroupId(val1)];
			idToInterval[val] = intervals.insert(next(intervalIt), { val, val });
		}

		auto interval = idToInterval[val];
		if (interval != intervals.begin() && prev(interval)->second == val - 1) {
			unionBelongingIntervals(val, val - 1);
		}
		if (next(interval) != intervals.end() && next(interval)->first == val + 1) {
			unionBelongingIntervals(val, val + 1);
		}

		s.insert(val);
	}

	vector<vector<int>> getIntervals() {
		vector<vector<int>> res(intervals.size(), vector<int>(2));
		int count = 0;
		for (const auto& interval : intervals) {
			res[count][0] = interval.first;
			res[count][1] = interval.second;
			count++;
		}
		return move(res);
	}
private:
	int findGroupId(int val) {
		int p = val;
		while (parent.find(p) != parent.end()) {
			p = parent[p];
		}
		int q = val;
		while (q != p) {
			int tmp = parent[q];
			parent[q] = p;
			q = tmp;
		}
		return p;
	}

	void unionGroup(int val1, int val2) {
		int id1 = findGroupId(val1), id2 = findGroupId(val2);
		if (id1 != id2) {
			parent[id2] = id1;
		}
	}

	void unionBelongingIntervals(int val1, int val2) {
		int id1 = findGroupId(val1), id2 = findGroupId(val2);
		auto it1 = idToInterval[id1];
		auto it2 = idToInterval[id2];
		it1->first = min(it1->first, it2->first);
		it1->second = max(it1->second, it2->second);
		intervals.erase(it2);
		idToInterval.erase(id2);
		unionGroup(val1, val2);
	}
};