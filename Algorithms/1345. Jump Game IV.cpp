class Solution {
    inline void tryUpdate(int from, int to, vector<int> &f, list<int> &li) {
        if (to >= 0 && to < f.size() && f[to] == -1) {
            f[to] = f[from] + 1;
            li.push_back(to);
        }
    }
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        unordered_map<int, bool> done;
        vector<int> f(n, -1);
        
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
            done[arr[i]] = false;
        }
        list<int> li = { 0 };
        f[0] = 0;
        while (!li.empty()) {
            int p = li.front();
            li.pop_front();
            
            tryUpdate(p, p - 1, f, li);
            tryUpdate(p, p + 1, f, li);
            if (!done[arr[p]]) {
                for (int to : mp[arr[p]]) {
                    tryUpdate(p, to, f, li);
                }
                done[arr[p]] = true;
            }
        }
        
        return f[n - 1];
    }
};