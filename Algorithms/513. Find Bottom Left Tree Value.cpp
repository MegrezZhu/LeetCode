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
    int findBottomLeftValue(TreeNode* root) {
        list<TreeNode*> li({root});
        int ans = -1;
        while (!li.empty()) {
            ans = li.front()->val;
            list<TreeNode*> li1;
            for (auto p : li) {
                if (p->left) li1.push_back(p->left);
                if (p->right) li1.push_back(p->right);
            }
            li = move(li1);
        }
        return ans;
    }
};