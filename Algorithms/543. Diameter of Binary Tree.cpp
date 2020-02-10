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
    int diameterOfBinaryTree(TreeNode* root) {
        return max(find(root).first - 1, 0);
    }
    
    pair<int, int> find(TreeNode* root) {
        // return: <longest, deepest>
        if (!root) return {0, 0};
        auto left = find(root->left);
        auto right = find(root->right);
        int deep = max(left.second, right.second) + 1;
        int long0 = left.second + 1 + right.second;
        int long1 = max(left.first, right.first);
        return {max(long0, long1), deep};
    }
};