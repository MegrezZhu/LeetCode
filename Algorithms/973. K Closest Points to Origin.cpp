class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<double, size_t>> q; // <dist, ind>, largest at top
        for (size_t i = 0; i < points.size(); i++) {
            const auto& v = points[i];
            double dist = sqrt(v[0] * v[0] + v[1] * v[1]);
            if (q.size() < K) {
                q.push({dist, i});
            } else if (dist < q.top().first) {
                q.pop();
                q.push({dist, i});
            }
        }
        vector<vector<int>> res;
        while (!q.empty()) {
            auto ind = q.top().second;
            res.push_back(move(points[ind]));
            q.pop();
        }
        return res;
    }
};