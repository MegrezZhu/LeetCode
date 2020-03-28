class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> mp;
        int ans = -1;
        const static int LIMIT = 2;
        for (int l = 0, r = 0; r < tree.size(); r++) {
            mp[tree[r]]++;
            while (mp.size() > LIMIT) {
                int &v = mp[tree[l]];
                v--;
                if (v == 0) {
                    mp.erase(tree[l]);
                }
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};