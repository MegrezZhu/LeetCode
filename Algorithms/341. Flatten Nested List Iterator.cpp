/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
	typedef pair<const vector<NestedInteger>*, vector<NestedInteger>::const_iterator> Context; // second must be integer
	stack<Context> stk;

	void decompose(const NestedInteger &ni) {
		auto p = &ni;
		while (!p->isInteger()) {
			auto& list = p->getList();
			if (list.size()) {
				// ni not an empty list
				auto context = make_pair(&list, list.begin());
				stk.push(context);
				p = &*list.begin();
			}
			else break;
		}
	}

	int getCurrent() {
		skipNull();
		auto context = stk.top();
		return context.second->getInteger();
	}

	bool isEmptyList(const NestedInteger &ni) {
		return !ni.isInteger() && ni.getList().empty();
	}

	void moveNext() {
		while (true) {
			stk.top().second++;
			if (stk.top().second == stk.top().first->end()) {
				stk.pop();
				if (stk.empty()) break;
			}
			else break;
		}
		if (!stk.empty()) decompose(*stk.top().second);
	}

	void skipNull() {
		while (!stk.empty() && isEmptyList(*stk.top().second)) moveNext();
	}

public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		if (nestedList.empty()) return;
		stk.push(make_pair(&nestedList, nestedList.cbegin()));
		decompose(nestedList.front());
	}

	int next() {
		int result = getCurrent();

		moveNext();

		return result;
	}

	bool hasNext() {
		skipNull();
		return !stk.empty();
	}
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */