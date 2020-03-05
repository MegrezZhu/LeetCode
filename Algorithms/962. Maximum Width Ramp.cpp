class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        map<int, list<int>> mp; // val -> [pos]
        for (int i = 0; i < A.size(); i++) {
            mp[A[i]].push_back(i);
        }
        int left = 1e9, ramp = -1;
        for (const auto &p : mp) {
            int v = p.first;
            const auto &li = p.second;
            
            left = min(left, li.front());
            int right = li.back();
            ramp = max(ramp, right - left);
        }
        return ramp;
    }
};