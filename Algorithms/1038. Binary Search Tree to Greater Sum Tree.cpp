/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        convert(root);
        return root;
    }
    
    int convert(TreeNode* root, int upSum = 0) { // return sum of nodes
        if (!root) {
            return 0;
        }
        int rightSum = convert(root->right, upSum);
        int leftSum = convert(root->left, upSum + root->val + rightSum);
        int sum = leftSum + root->val + rightSum;
        root->val += rightSum + upSum;
        
        return sum;
    }
};