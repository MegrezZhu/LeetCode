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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> s(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;
        
        if (!del(root, s, ans)) {
            ans.push_back(root);
        }
        
        return ans;
    }
    
    bool del(TreeNode *root, set<int> &to_delete, vector<TreeNode*> &ans) {
        if (!root) return true;
        
        if (to_delete.find(root->val) != to_delete.end()) {
            to_delete.erase(root->val);
            if (!del(root->left, to_delete, ans)) {
                ans.push_back(root->left);
            }
            if (!del(root->right, to_delete, ans)) {
                ans.push_back(root->right);
            }
            return true;
        } else {
            if (del(root->left, to_delete, ans)) {
                root->left = NULL;
            }
            if (del(root->right, to_delete, ans)) {
                root->right = NULL;
            }
            return false;
        }
    }
};