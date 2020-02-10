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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        list<TreeNode*> next = {root};
        vector<double> ans;
        while (!next.empty()) {
            double sum = 0;
            for (auto it: next) sum += it->val;
            ans.push_back(sum / next.size());
            auto li = move(next);
            next.clear();
            while (!li.empty()) {
                auto p = li.front();
                li.pop_front();
                if (p->left) next.push_back(p->left);
                if (p->right) next.push_back(p->right);
            }
        }
        return ans;
    }
};