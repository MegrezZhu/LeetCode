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
    int pathSum(TreeNode* root, int sum) {
        vector<int> tmp;
        return pathSum(root, sum, tmp);
    }
    
    int pathSum(TreeNode* root, int sum, vector<int> &path) {
        if (!root) return 0;
        int res = 0;
        
        path.push_back(root->val);
        for (int i = path.size() - 1, s = 0; i >= 0; i--) {
            s += path[i];
            if (s == sum) res++;
        }
        res += pathSum(root->left, sum, path);
        res += pathSum(root->right, sum, path);
        path.pop_back();
        
        return res;
    }
};