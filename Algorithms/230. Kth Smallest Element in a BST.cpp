/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct KTreeNode {
    int val, count;
    KTreeNode *left;
    KTreeNode *right;
    KTreeNode(TreeNode* ori): count(1) {
        val = ori->val;
        left = ori->left ? new KTreeNode(ori->left) : NULL;
        right = ori->right ? new KTreeNode(ori->right) : NULL;
        if (left) count += left->count;
        if (right) count += right->count;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return kthSmallest(new KTreeNode(root), k);
    }
    int kthSmallest(KTreeNode* root, int k) {
        int mid = root->left ? root->left->count : 0;
        if (k <= mid) return kthSmallest(root->left, k);
        if (k == mid + 1) return root->val;
        return kthSmallest(root->right, k - mid - 1);
    }
};