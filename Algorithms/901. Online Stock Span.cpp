class StockSpanner {
    int count;
    vector<pair<int, int>> q; // <val, pos> in descending order
public:
    StockSpanner(): count(0) {}
    
    int next(int price) {
        count++;

        while (!q.empty() && q.back().first <= price) {
            q.pop_back();
        }
        q.push_back({ price, count });
        
        if (q.empty() || q.front().first <= price) {
            return count;
        }
        int l = 0, r = q.size() - 1;
        
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (q[mid].first > price) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return count - q[l].second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */