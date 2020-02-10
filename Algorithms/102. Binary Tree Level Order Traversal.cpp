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
    vector<vector<int>> levelOrder(TreeNode* root) {
        list<TreeNode*> now = { root };
        vector<vector<int>> result;
        if (!root) return result;
        while (now.size() != 0) {
            list<TreeNode*> next;
            vector<int> level;
            for (auto t : now) {
                level.push_back(t->val);
                if (t->left) {
                    next.push_back(t->left);
                }
                if (t->right) {
                    next.push_back(t->right);
                }
            }
            result.push_back(move(level));
            now = move(next);
        }
        return result;
    }
};