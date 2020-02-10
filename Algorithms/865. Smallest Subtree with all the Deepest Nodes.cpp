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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return find(root).second;
    }
    
    pair<int, TreeNode*> find(TreeNode* root) { // <max depth, sol>
        if (!root) return {0, NULL};
        auto l = find(root->left);
        auto r = find(root->right);
        if (l.first == r.first) return {l.first + 1, root};
        if (l.first > r.first) return {l.first + 1, l.second};
        return {r.first + 1, r.second};
    }
};