class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        using Tuple = tuple<int, size_t, size_t>;
        priority_queue<Tuple, vector<Tuple>, greater<Tuple>> q; // <value, v_index, index>
        size_t m = nums.size();
        for (size_t i = 0; i < m; i++) {
            if (!nums[i].empty()) {
                q.push(make_tuple(nums[i][0], i, 0));
            }
        }
        
        int ansl = 1e9, ansr = 2e9;
        size_t left = m;
        list<pair<int, size_t>> li;
        vector<int> count(m, 0);
        bool fulfilled = false;
        while (!q.empty()) {
            auto top = q.top();
            q.pop();
            int v = get<0>(top);
            size_t qi = get<1>(top), i = get<2>(top);
            
            if (i + 1 < nums[qi].size()) {
                q.push(make_tuple(nums[qi][i + 1], qi, i + 1));
            }
            
            li.push_back(make_pair(v, qi));
            count[qi]++;
            if (count[qi] == 1) { // just covered 
                left--;
                if (left == 0) fulfilled = true;
            }
            while (count[li.front().second] > 1) {
                count[li.front().second]--;
                li.pop_front();
            }
            if (fulfilled) {
                int l = li.front().first, r = li.back().first;
                if (r - l < ansr - ansl || r - l == ansr - ansl && l < ansl) {
                    ansl = l;
                    ansr = r;
                }
            }
        }
        return vector<int>({ansl, ansr});
    }
};