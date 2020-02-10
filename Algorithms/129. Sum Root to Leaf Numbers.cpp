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
    int sumNumbers(TreeNode* root, int now = 0) {
        if (!root) return 0;
        if (!root->left && !root->right) return now * 10 + root->val;
        return sumNumbers(root->left, now * 10 + root->val) + sumNumbers(root->right, now * 10 + root->val);
    }
};