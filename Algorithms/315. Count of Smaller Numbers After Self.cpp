class Node {
    Node *left, *right;
    int count, val, _size;
public:
    Node(int val) {
        left = right = NULL;
        _size = count = 1;
        this->val = val;
    }
    int insert(int val) {
        this->_size++;
        if (this->val == val) {
            this->count++;
            return this->left ? this->left->size() : 0;
        } else {
            if (val < this->val) {
                if (this->left) 
                    return this->left->insert(val);
                else {
                    this->left = new Node(val);
                    return 0;
                }
            } else {
                int leftSize = count + (this->left ? this->left->size() : 0);
                if (this->right) 
                    return leftSize + this->right->insert(val);
                else {
                    this->right = new Node(val);
                    return leftSize;
                }
            }
        }
    }
    const int size() {
        return _size;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) return {};
        int n = nums.size();
        auto root = new Node(nums[n - 1]);
        vector<int> ans(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = root->insert(nums[i]);
        }
        return ans;
    }
};