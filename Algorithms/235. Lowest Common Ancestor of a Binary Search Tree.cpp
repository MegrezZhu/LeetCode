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
    TreeNode* nextNode(TreeNode* now, int val) {
        if (val == now->val) return now;
        if (val > now->val) return now->right;
        return now->left;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (true) {
            auto tmp = nextNode(root, p->val);
            if (tmp != nextNode(root, q->val)) return root;
            root = tmp;
        }
    }
};