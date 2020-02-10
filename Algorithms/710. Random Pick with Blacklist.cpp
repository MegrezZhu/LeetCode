class Solution {
    int N;
    vector<pair<int, int>> v;
public:
    Solution(int N, vector<int>& blacklist) {
        this->N = N - blacklist.size();
        sort(blacklist.begin(), blacklist.end());
        int l = 0, leftLen = 0;
        for (int i = 0; i < blacklist.size(); i++) {
            if (blacklist[i] - l > 0) {
                v.push_back({leftLen, l}); // <v', v>
                leftLen += blacklist[i] - l;
            }
            l = blacklist[i] + 1;
        }
        if (l != N) v.push_back({leftLen, l});
    }
    
    int pick() {
        int t = rand() % N;
        auto it = upper_bound(v.begin(), v.end(), make_pair(t, int(1e9)));
        it--;
        return t - it->first + it->second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */