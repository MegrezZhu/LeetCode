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
    bool isValidBST(TreeNode* root, long left = -2e11, long right = 2e11) {
        if (!root) return true;
        long val = root->val;
        if (val <= left || val >= right) return false;
        return isValidBST(root->left, left, min(right, long(val))) && isValidBST(root->right, max(left, long(val)), right);
    }
};