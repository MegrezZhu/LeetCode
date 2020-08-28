class Solution {
public:
    vector<int> advantageCount(const vector<int>& A, const vector<int>& B) {
        vector<int> ans;
        map<int, int> mp; // number in A -> count
        for (int x : A) mp[x]++;
        for (int y : B) {
            auto it = mp.upper_bound(y);
            if (it == mp.end()) it = mp.begin();

            ans.push_back(it->first);
            if (--it->second == 0) {
                mp.erase(it);
            }
        }
        return ans;
    }
};