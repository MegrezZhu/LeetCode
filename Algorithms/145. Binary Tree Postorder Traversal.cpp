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
    vector<int> res;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        res.clear();
        traverse(root);
        return res;
    }
    
    void traverse(TreeNode* root) {
        if (!root) return;
        traverse(root->left);
        traverse(root->right);
        res.push_back(root->val);
    }
};