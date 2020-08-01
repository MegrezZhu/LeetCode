class Solution {
public:
    int minTaps(int n, const vector<int>& ranges) {
        int count = 0, pos = 0;

        vector<int> leftPointRank;
        for (int i = 0; i <= n; i++) {
            leftPointRank.push_back(i);
        }
        sort(
            leftPointRank.begin(),
            leftPointRank.end(),
            [&](int a, int b) { return a - ranges[a] < b - ranges[b]; }
        );
        
        int i = 0;
        while (pos < n) {
            int rightMost = pos;
			while (i < leftPointRank.size() && leftPointRank[i] - ranges[leftPointRank[i]] <= pos) {
				rightMost = max(rightMost, leftPointRank[i] + ranges[leftPointRank[i]]);
				i++;
			}
            if (rightMost > pos) {
                count++;
                pos = rightMost;
            } else {
                return -1;
            }
        }
        return pos >= n ? count : -1;
    }
};