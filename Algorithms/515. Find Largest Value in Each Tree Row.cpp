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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        list<TreeNode*> parent = { root };
        while (!parent.empty()) {
            list<TreeNode*> son;
            int _max = -2147483648;
            while (!parent.empty()) {
                auto p = parent.front();
                parent.pop_front();
                if (p->left) son.push_back(p->left);
                if (p->right) son.push_back(p->right);
                _max = max(_max, p->val);
            }
            res.push_back(_max);
            parent = move(son);
        }
        
        return res;
    }
};