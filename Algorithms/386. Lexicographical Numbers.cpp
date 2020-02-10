class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        result.reserve(n);
        walk(result, n, 0);
        return result;
    }
    void walk(vector<int> &res, int limit, int pre) {
        if (pre > limit) return;
        if (pre == 0) {
            for (int i = 1; i <= 9; i++) walk(res, limit, i);
        } else {
            res.push_back(pre);
            for (int i = 0; i <= 9; i++) {
                int v = pre * 10 + i;
                if (v > limit) return;
                walk(res, limit, v);
            }
        }
    }
};