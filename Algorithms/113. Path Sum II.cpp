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
    void traverse(vector<vector<int>>& res, vector<int>& path, TreeNode* root, int sum) {
        if (!root) return;
        
        path.push_back(root->val);
        traverse(res, path, root->left, sum - root->val);
        traverse(res, path, root->right, sum - root->val);
        if (!root->left && !root->right && sum - root->val == 0) res.push_back(path);
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        traverse(res, path, root, sum);
        return res;
    }
};