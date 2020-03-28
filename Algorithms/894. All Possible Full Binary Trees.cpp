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
    vector<TreeNode*> allPossibleFBT(int N) {
        if (N % 2 == 0) return {};
        
        unordered_map<int, vector<TreeNode*>> mp;
        mp[1].push_back(new TreeNode(0));
        for (int i = 3; i <= N; i += 2) {
            for (int j = 1; j < i; j += 2) {
                int k = i - j - 1;
                const auto &left = mp[j];
                const auto &right = mp[k];
                auto &mid = mp[i];
                for (auto pleft : left) {
                    for (auto pright: right) {
                        auto root = new TreeNode(0);
                        root->left = pleft;
                        root->right = pright;
                        mid.push_back(root);
                    }
                }
            }
        }
        
        return mp[N];
    }
    
//     TreeNode* clone(TreeNode* root) {
//         if (!root) return NULL;
//         auto p = new TreeNode(0);
//         p->left = clone(root->left);
//         p->right = clone(root->right);
        
//         return p;
//     }
};