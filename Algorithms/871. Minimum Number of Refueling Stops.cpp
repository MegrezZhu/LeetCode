class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> q;
        int pos = -1, coverLen = 0;
        int count = 0;
        q.push(startFuel);
        while (!q.empty() && coverLen < target) {
            coverLen += q.top();
            count++;
            q.pop();
            while (pos + 1 < stations.size() && stations[pos + 1][0] <= coverLen) {
                q.push(stations[++pos][1]);
            }
        }
        if (coverLen >= target) return count - 1;
        else return -1;
    }
};