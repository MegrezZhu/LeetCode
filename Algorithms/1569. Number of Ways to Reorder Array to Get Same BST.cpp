class Solution {
	using LL = long long;
	const static LL MOD = 1e9 + 7;

	static LL inverse(LL a) {
		auto [s, t, gcd] = extended_euclidean(a, MOD);
		return (s + (s / MOD + 1) * MOD) % MOD;
	}

	static tuple<LL, LL, LL> extended_euclidean(LL a, LL b) {
		if (b == 0) {
			return { 1, 0, 0 };
		}
		LL old_r = a, r = b;
		LL old_s = 1, s = 0;
		LL old_t = 0, t = 1;
		while (r != 0) {
			LL q = old_r / r;
			LL temp = old_r;
			old_r = r;
			r = temp - q * r;
			temp = old_s;
			old_s = s;
			s = temp - q * s;
			temp = old_t;
			old_t = t;
			t = temp - q * t;
		}
		return { old_s, old_t, old_r };
	}

	static LL mult(LL a, LL b) {
		return (a * b) % MOD;
	}

	static LL divide(LL a, LL b) {
		auto inv = inverse(b);
		return mult(a, inv);
	}

	static LL factorial(LL x) {
		LL ret = 1;
		for (auto i = 2; i <= x; i++) {
			ret = mult(ret, i);
		}
		return ret;
	}

	// returns number of ways to mix to arrays with length a & b, without changing
	// the ordering of elements in the two arrays.
	// Equals A(a+b)/(A(a)*A(b))
	static LL mix(LL a, LL b) {
		auto ret = factorial(a + b);
		ret = divide(ret, factorial(a));
		ret = divide(ret, factorial(b));
		return ret;
	}

	// partitions the array [l, r] using v[l] as pivot
	static void partition(vector<int>& v, int l, int r) {

	}
public:
	int numOfWays(const vector<int>& nums) {
		return (_numOfWays(nums) - 1 + MOD) % MOD;
	}

	int _numOfWays(const vector<int>& nums) {
		if (nums.size() <= 1) {
			return 1;
		}
		vector<int> l, r;
		int root = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			(nums[i] <= root ? l : r).push_back(nums[i]);
		}
		LL ret = mult(_numOfWays(l), _numOfWays(r));
		ret = mult(ret, mix(l.size(), r.size()));
		return ret;
	}
};