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
    pair<TreeNode*, int> convert(TreeNode* root, int plus = 0) {
        if (!root) return make_pair(nullptr, 0);
        TreeNode *newRoot = new TreeNode(root->val);
        auto pRight = convert(root->right, plus);
        auto pLeft = convert(root->left, root->val + pRight.second + plus);
        newRoot->left = pLeft.first;
        newRoot->right = pRight.first;
        auto result = make_pair(newRoot, newRoot->val + pLeft.second + pRight.second);
        newRoot->val += pRight.second + plus;
        
        return result;
    }
public:
    TreeNode* convertBST(TreeNode* root, int plus = 0) {
        return convert(root).first;
    }
};