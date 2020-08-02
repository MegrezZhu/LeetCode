class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return maxProfit(2, prices);
    }

	int maxProfit(int k, const vector<int>& prices) {
		int n = prices.size();
		vector<int> f(n, 0);

		int ans = 0;
		for (int i = 0; i < k; i++) {
			vector<int> nextF(n, 0);
            bool improved = false;
			int maxF = 0, maxx = -1e9;
			for (int j = 0; j < n; j++) {
				if (j > 0) maxF = max(maxF, f[j - 1]);
				maxx = max(maxx, -prices[j] + maxF);
				nextF[j] = prices[j] + maxx;
                
                if (nextF[j] > ans) {
                    improved = true;
                    ans = nextF[j];
                }
			}
            if (!improved) break;
			f = move(nextF);
		}
		return ans;
	}
};