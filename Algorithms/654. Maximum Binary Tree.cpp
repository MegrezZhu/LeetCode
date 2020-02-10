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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size() - 1);
    }
    
    TreeNode* construct(vector<int>& nums, int l, int r) {
        if (l > r) return NULL;
        int mmax = -2e9, mpos;
        for (int i = l; i <= r; i++) {
            if (nums[i] > mmax) {
                mmax = nums[i];
                mpos = i;
            }
        }
        auto node = new TreeNode(mmax);
        node->left = construct(nums, l, mpos - 1);
        node->right = construct(nums, mpos + 1, r);
        return node;
    }
};