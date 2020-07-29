class Solution {
public:
    int countPrimes(int n) {
        vector<bool> flag(n); // false if prime
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (!flag[i]) {
                count++;
            }
            for (int j = 2; i * j < n; j++) {
                flag[i * j] = true;
                if (i % j == 0) break;
            }
        }
        return count;
    }
};