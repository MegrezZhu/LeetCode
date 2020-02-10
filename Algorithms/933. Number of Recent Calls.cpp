class RecentCounter {
    list<int> history;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        history.push_back(t);
        while (history.front() + 3000 < history.back()) history.pop_front();
        return history.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */