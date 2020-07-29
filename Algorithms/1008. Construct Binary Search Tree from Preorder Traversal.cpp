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
    TreeNode* bstFromPreorder(const vector<int>& preorder) {
        return construct(preorder, 0, preorder.size() - 1);
    }
    
    TreeNode* construct(const vector<int>& order, int l, int r) {
        if (l > r) return NULL;
        if (l == r) return new TreeNode(order[l]);
        int mid = l;
        while (mid < r && order[mid + 1] < order[l]) mid++;
        return new TreeNode(order[l], construct(order, l + 1, mid), construct(order, mid + 1, r));
    }
};