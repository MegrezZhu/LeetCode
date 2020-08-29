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
    int maxAncestorDiff(TreeNode* root, int minn = 1e9, int maxx = -1e9) {
        if (!root) return 0;
        minn = min(minn, root->val);
        maxx = max(maxx, root->val);
        return max(
            maxx - minn,
            max(maxAncestorDiff(root->left, minn, maxx), maxAncestorDiff(root->right, minn, maxx))
        );
    }
};