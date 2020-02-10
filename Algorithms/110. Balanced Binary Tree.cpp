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
    pair<bool, int> _isBalanced(TreeNode* root) {
        if (!root) return { true, 0 };
        auto left = _isBalanced(root->left);
        auto right = _isBalanced(root->right);
        int height = max(left.second, right.second) + 1;
        if (!left.first || !right.first) return { false, height };
        return { abs(left.second - right.second) <= 1, height };
    }
public:
    bool isBalanced(TreeNode* root) {
        return _isBalanced(root).first;
    }
};