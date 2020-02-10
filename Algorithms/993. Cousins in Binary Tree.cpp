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
    bool isCousins(TreeNode* root, int x, int y) {
        auto rx = find(root, x);
        auto ry = find(root, y);
        return rx.first == ry.first && rx.second != ry.second;
    }
    pair<int, int> find(TreeNode* root, int val, int depth = 0, int parent = -1) {
        if (!root) return { -1, -1 };
        if (root->val == val) return { depth, parent };
        auto res = find(root->left, val, depth + 1, root->val);
        if (res.first == -1) return find(root->right, val, depth + 1, root->val);
        else return res;
    }
};