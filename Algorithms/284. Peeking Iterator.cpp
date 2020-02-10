// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
    bool buffed;
    int buff;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    this->buffed = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (!this->buffed) {
            this->buff = Iterator::next();
            this->buffed = true;
        }
        return this->buff;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if (this->buffed) {
            this->buffed = false;
            return this->buff;
        } else {
            return Iterator::next();
        }
	}

	bool hasNext() const {
	    return Iterator::hasNext() || this->buffed;
	}
};