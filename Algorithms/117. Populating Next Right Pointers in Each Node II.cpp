/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        
        TreeLinkNode *tail = new TreeLinkNode(0), *first = tail, *parent = root;
        while (parent) {
            tail->next = parent->left;
            if (parent->left) tail = tail->next;
            tail->next = parent->right;
            if (parent->right) tail = tail->next;
            parent = parent->next;
            if (!parent) {
                tail = first;
                parent = first->next;
            }
        }
    }
};