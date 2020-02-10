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
    TreeNode* ans;
    int search(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return 0;
        int isP = root == p ? 0b10 : 0b00;
        int isQ = root == q ? 0b01 : 0b00;
        int self = search(root->left, p, q) | search(root->right, p, q) | isP | isQ;
        if (self == 0b11 && ans == nullptr) ans = root;
        return self;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = nullptr;
        search(root, p, q);
        return ans;
    }
};