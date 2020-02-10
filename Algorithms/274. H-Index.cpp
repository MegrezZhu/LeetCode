class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        sort(citations.begin(), citations.end());
        if (citations.back() == 0) return 0;
        int h = 1;
        for (; h <= citations.size(); h++) {
            if (citations[citations.size() - h] >= h) continue;
            else break;
        }
        return h - 1;
    }
};