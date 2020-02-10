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
    pair<int, int> _rob(TreeNode* root) {
        if (!root) return { 0, 0 };
        auto left = _rob(root->left);
        auto right = _rob(root->right);
        return { root->val + left.second + right.second, max(left.first, left.second) + max(right.first, right.second) };
    }
public:
    int rob(TreeNode* root) {
        auto res = _rob(root);
        return max(res.first, res.second);
    }
};