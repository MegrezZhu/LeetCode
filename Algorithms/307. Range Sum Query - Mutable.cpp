
class SegmentTreeNode {
    int val, sum;
    int l, r;
    unique_ptr<SegmentTreeNode> left, right;

   public:
    SegmentTreeNode(const vector<int> &d, int l, int r) {
        if (l == r) {
            this->val = this->sum = d[l];
        } else {
            int mid = (l + r) / 2;
            this->left = make_unique<SegmentTreeNode>(d, l, mid);
            this->right = make_unique<SegmentTreeNode>(d, mid + 1, r);
            this->sum = this->left->getSum() + this->right->getSum();
        }
        this->l = l;
        this->r = r;
    }

    int getSum() { return this->sum; }

    int getSum(int l, int r) {
        l = max(this->l, l);
        r = min(this->r, r);
        if (l > r) return 0;  // segment not overlapping
        if (l == this->l && r == this->r) return this->sum;
        int lsum = this->left ? this->left->getSum(l, r) : 0;
        int rsum = this->right ? this->right->getSum(l, r) : 0;
        return lsum + rsum;
    }

    void update(int pos, int val) {
        if (this->l == this->r && this->l == pos) {
            this->val = this->sum = val;
            return;
        }
        int mid = (this->l + this->r) / 2;
        if (pos <= mid)
            this->left->update(pos, val);
        else
            this->right->update(pos, val);
        this->sum = this->left->getSum() + this->right->getSum();
    }
};

class NumArray {
    unique_ptr<SegmentTreeNode> tree;
   public:
    NumArray(vector<int> nums) {
        if (nums.size())
            this->tree = make_unique<SegmentTreeNode>(nums, 0, nums.size() - 1);
    }

    void update(int i, int val) {
        if (this->tree)
            this->tree->update(i, val);
    }

    int sumRange(int i, int j) {
        if (this->tree)
            return this->tree->getSum(i, j);
        else
            return 0;
    }
};
