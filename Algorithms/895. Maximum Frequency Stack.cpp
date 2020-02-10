class FreqStack {
	vector<vector<int>> s;
	unordered_map<int, int> mp;
public:
	FreqStack() {
	}

	void push(int x) {
		auto& count = mp[x];
		count++;
		if (count > s.size()) s.push_back({});
		s[count - 1].push_back(x);
	}

	int pop() {
		int res = s.back().back();
		mp[res]--;
		s.back().pop_back();
		if (s.back().empty()) s.pop_back();
		return res;
	}
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */