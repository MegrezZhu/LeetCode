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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *p = root, *last;
        while (p) {
            last = p;
            if (val > p->val) p = p->right;
            else p = p->left;
        }
        if (val > last->val) last->right = new TreeNode(val);
        else last->left = new TreeNode(val);
        
        return root;
    }
};