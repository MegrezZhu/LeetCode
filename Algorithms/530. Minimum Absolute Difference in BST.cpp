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
    int getMinimumDifference(TreeNode* root) {
        return find(root).second;
    }
    
    pair<pair<int, int>, int> find(TreeNode* root) {
        int minn = root->val, maxx = minn, ans = 1e9;
        
        if (root->left) {
            auto res = find(root->left);
            ans = min(ans, res.second);
            ans = min(ans, root->val - res.first.second);
            
            minn = min(minn, res.first.first);
            maxx = max(maxx, res.first.second);
        }
        
        if (root->right) {
            auto res = find(root->right);
            ans = min(ans, res.second);
            ans = min(ans, res.first.first - root->val);
            
            minn = min(minn, res.first.first);
            maxx = max(maxx, res.first.second);
        }
        
        return { { minn, maxx }, ans };
    }
};