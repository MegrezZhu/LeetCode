class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> f(amount + 1, 0);
        f[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                f[i] += f[i - coin];
            }
        }
        return f[amount];
    }
};