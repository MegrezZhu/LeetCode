class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size(), count = 0;
        vector<int> pos(n);
        for (int i = 0; i < n; i++) pos[row[i]] = i;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) continue;
            if (!isCouple(row[i], row[i - 1])) {
                int original = row[i];
                int toFind = (row[i - 1] % 2 == 0) ? (row[i - 1] + 1) : (row[i - 1] - 1);
                swap(row[i], row[pos[toFind]]);
                swap(pos[original], pos[toFind]);
                count++;
            }
        }
        return count;
    }
private:
    bool isCouple(int x, int y) {
        return x / 2 == y / 2;
    }
};