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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> ans;
        traverse(vector<TreeNode*>{root}, ans);
        return ans;
    }
    
    void traverse(const vector<TreeNode*> level, vector<vector<int>> &ans) {
        if (level.empty()) {
            return;
        }
        vector<int> vals;
        vector<TreeNode*> next;
        for (auto p : level) {
            vals.push_back(p->val);
            if (p->left) {
                next.push_back(p->left);
            }
            if (p->right) {
                next.push_back(p->right);
            }
        }
        traverse(next, ans);
        ans.push_back(move(vals));
    }
};