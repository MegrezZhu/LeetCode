class DinnerPlates {
    set<int> nonFull, nonEmpty;
    vector<stack<int>> vs;
    int cap;
public:
    DinnerPlates(int capacity): cap(capacity) {}
    
    void push(int val) {
        if (nonFull.empty()) {
            vs.push_back(move(stack<int>()));
            nonFull.insert(vs.size() - 1);
        }
        int id = *nonFull.begin();
        vs[id].push(val);
        if (vs[id].size() == cap) {
            nonFull.erase(id);
        }
        if (vs[id].size() == 1) {
            nonEmpty.insert(id);
        }
    }
    
    int pop() {
        if (nonEmpty.empty()) {
            return -1;
        }
        return popAtStack(*nonEmpty.rbegin());
    }
    
    int popAtStack(int id) {
        if (id >= vs.size() || vs[id].empty()) {
            return -1;
        }
        int val = vs[id].top();
        vs[id].pop();
        if (vs[id].size() == cap - 1) {
            nonFull.insert(id);
        }
        if (vs[id].empty()) {
            nonEmpty.erase(id);
        }
        return val;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */