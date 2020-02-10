class MedianFinder {
	vector<int> left, right;
	int size;
public:
	/** initialize your data structure here. */
	MedianFinder() {
		size = 0;
	}

	void addNum(int num) {
		size++;
		int leftCap = (size + 1) / 2, rightCap = size - leftCap;
		if (left.size() < leftCap) {
			int toLeft;
			if (right.size() == 0 || num <= right.front()) {
				toLeft = num;
			} else {
				toLeft = right.front();
				pop_heap(right.begin(), right.end(), greater<int>());
				right.pop_back();
				right.push_back(num);
				push_heap(right.begin(), right.end(), greater<int>());
			}
			left.push_back(toLeft);
			push_heap(left.begin(), left.end());
		}
		else {
			int toRight;
			if (left.size() == 0 || num >= left.front()) {
				toRight = num;
			}
			else {
				toRight = left.front();
				pop_heap(left.begin(), left.end());
				left.pop_back();
				left.push_back(num);
				push_heap(left.begin(), left.end());
			}
			right.push_back(toRight);
			push_heap(right.begin(), right.end(), greater<int>());
		}
	}

	double findMedian() const {
		if (size % 2) return left.front();
		else return (left.front() + right.front()) / 2.0;
	}
};