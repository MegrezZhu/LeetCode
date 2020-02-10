class Solution {
public:
	string getPermutation(int n, int k) {
		string res;
		int base = 1;
		for (int i = 1; i <= n; i++) base *= i;
		vector<int> dict;
		for (int i = 1; i <= n; i++) dict.push_back(i);
		size_t ind = 0;
		k--;
		while (n) {
			base /= n;
			int a = k / base;
			res.push_back(dict[a] + '0');
			dict.erase(dict.begin() + a);
			k = k % base;
			n--;
		}
		return res;
	}
};