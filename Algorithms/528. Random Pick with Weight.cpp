class Solution {
    vector<int> v;
    int n;
public:
    Solution(vector<int>& w): v(w.size(), 0) {
        v[0] = w[0];
        for (int i = 1; i < w.size(); i++) v[i] = v[i - 1] + w[i];
        n = v.back();
    }
    
    int pickIndex() {
        int t = rand() % n;
        return upper_bound(v.begin(), v.end(), t) - v.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */