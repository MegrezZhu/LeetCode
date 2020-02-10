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
    string wrap(const string &str) {
        return '(' + str + ')';
    }
public:
    string tree2str(TreeNode* t) {
        if (!t) return "";
        auto left = t->left ? wrap(tree2str(t->left)) : "";
        auto right = t->right ? wrap(tree2str(t->right)) : "";
        if (left.empty() && !right.empty()) left = "()";
        return to_string(t->val) + left + right;
    }
};