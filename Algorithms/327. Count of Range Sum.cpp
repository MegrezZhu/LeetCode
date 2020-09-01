struct AVL {
	using LL = long long;

	LL val, minv, maxv;
	int depth, size, delta;
	AVL* left, * right;

	AVL(LL val) : val(val), left(NULL), right(NULL), size(1), minv(val), maxv(val), depth(1), delta(0) {}

	void insert(LL x) {
		if (x <= val) {
			if (!left) {
				left = new AVL(x);
			}
			else {
				left->insert(x);
			}
		}
		else {
			if (!right) {
				right = new AVL(x);
			}
			else {
				right->insert(x);
			}
		}
		size++;
		minv = min(minv, x);
		maxv = max(maxv, x);
		update();

		if (abs(delta) > 1) { // imbalanced.
			if (delta > 0) {
				if (left->delta == 1) { // LL
					rotateLL(this);
				}
				else { // LR
					rotateRR(left);
					rotateLL(this);
				}
			}
			else {
				if (right->delta == -1) { // RR
					rotateRR(this);
				}
				else { // RL
					rotateLL(right);
					rotateRR(this);
				}
			}
		}
	}

	int count(LL l, LL r) {
		if (l <= minv && maxv <= r) {
			return size;
		}
		if (maxv < l || minv > r) {
			return 0;
		}
		if (l > val) {
			return right ? right->count(l, r) : 0;
		}
		if (r < val) {
			return left ? left->count(l, r) : 0;
		}
		return 1 + (left ? left->count(l, r) : 0) + (right ? right->count(l, r) : 0);
	}

private:
	void update() {
		int ldepth = left ? left->depth : 0, rdepth = right ? right->depth : 0;
		int lsize = left ? left->size : 0, rsize = right ? right->size : 0;
		size = 1 + lsize + rsize;
		depth = max(ldepth, rdepth) + 1;
		delta = ldepth - rdepth;

		minv = min(left ? left->minv : 1e9, right ? right->minv : 1e9);
		minv = min(minv, val);

		maxv = max(left ? left->maxv : -1e9, right ? right->maxv : -1e9);
		maxv = max(maxv, val);
	}

	static void rotateLL(AVL *root) {
		auto l = root->left;
		auto r = root->right;
		auto ll = l->left;
		auto lr = l->right;
		swap(root->val, l->val);

		root->left = ll;
		root->right = l;
		l->left = lr;
		l->right = r;

		if (root->left) {
			root->left->update();
		}
		if (root->right) {
			root->right->update();
		}
		root->update();
	}

	static void rotateRR(AVL *root) {
		auto l = root->left;
		auto r = root->right;
		auto rl = r->left;
		auto rr = r->right;
		swap(root->val, r->val);

		root->left = r;
		root->right = rr;
		r->left = l;
		r->right = rl;

		if (root->left) {
			root->left->update();
		}
		if (root->right) {
			root->right->update();
		}
		root->update();
	}
};

class Solution {
	using LL = long long;
public:
	int countRangeSum(const vector<int>& nums, int lower, int upper) {
		AVL* root = new AVL(0);
		int ans = 0;
		for (LL i = 0, prefixSum = 0; i < nums.size(); i++) {
			prefixSum += nums[i];
			ans += root->count(LL(prefixSum) - upper, LL(prefixSum) - lower);

			root->insert(prefixSum);
		}
		return ans;
	}
};