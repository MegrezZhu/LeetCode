/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        return _minDepth(root);
    }
    int _minDepth(TreeNode* root) {
        if (!root) return 1e9;
        if (!root->left && !root->right) return 1;
        return 1 + min(_minDepth(root->left), _minDepth(root->right));
    }
};