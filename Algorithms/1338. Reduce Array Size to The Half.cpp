class Solution {
public:
    int minSetSize(const vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int x : arr) mp[x]++;
        vector<int> count;
        for (const auto &p : mp) count.push_back(p.second);
        sort(count.rbegin(), count.rend());
        
        int num = arr.size();
        for (int i = 0; i < count.size(); i++) {
            num -= count[i];
            if (num <= arr.size() / 2) return i + 1;
        }
        return -1;
    }
};