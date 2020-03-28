class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        set<int> times;
        for (int time : startTime) times.insert(time);
        for (int time : endTime) times.insert(time);
        
        unordered_map<int, int> timeMap;
        int index = -1;
        for (int time : times) timeMap[time] = ++index;
        
        int n = startTime.size();
        for (int i = 0; i < n; i++) {
            startTime[i] = timeMap[startTime[i]];
            endTime[i] = timeMap[endTime[i]];
        }
        
        vector<int> sorted(n, 0);
        for (int i = 0; i < n; i++) sorted[i] = i;
        sort(sorted.begin(), sorted.end(), [&](int a, int b) {
            return endTime[a] < endTime[b];
        });
        
        int last = endTime[sorted.back()];
        vector<int> f(last + 1, 0);
        for (int i = 1, j = 0; i <= last; i++) {
            f[i] = f[i - 1];
            while (j < n && endTime[sorted[j]] <= i) {
                f[i] = max(f[i], f[startTime[sorted[j]]] + profit[sorted[j]]);
                j++;
            }
        }
        
        return f[last];
    }
};