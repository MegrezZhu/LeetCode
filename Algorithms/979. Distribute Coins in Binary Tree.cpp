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
    int distributeCoins(TreeNode* root) {
        return distribute(root).first;
    }
    
    pair<int, int> distribute(TreeNode* root) {
        if (!root) return { 0, 0 };
        
        auto left = distribute(root->left);
        auto right = distribute(root->right);
        
        return { 
            left.first + right.first + abs(left.second) + abs(right.second),
            left.second + right.second + root->val - 1
        };
    }
};