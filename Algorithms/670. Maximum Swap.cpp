class Solution {
public:
    int maximumSwap(int num) {
        if (num == 0) return 0;
        auto v = convert(num);
        for (int i = 0; i < v.size() - 1; i++) {
            int maxx = -1, maxp;
            for (int j = v.size() - 1; j > i; j--) {
                if (v[j] > maxx && v[j] > v[i]) {
                    maxx = v[j];
                    maxp = j;
                }
            }
            if (maxx != -1) {
                swap(v[i], v[maxp]);
                return convert(v);
            }
        }
        return num;
    }
private:
    vector<int> convert(int num) {
        vector<int> res;
        while (num) {
            res.push_back(num % 10);
            num /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    int convert(const vector<int>& num) {
        int res = 0;
        for (int a : num) res = res * 10 + a;
        return res;
    }
};