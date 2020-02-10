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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (same(s, t)) return true;
        if (s && isSubtree(s->left, t)) return true;
        if (s && isSubtree(s->right, t)) return true;
        return false;
    }
    
    bool same(TreeNode* s, TreeNode* t) {
        if (!s || !t) return !t && !s;
        if (s->val != t->val) return false;
        return same(s->left, t->left) && same(s->right, t->right);
    }
};