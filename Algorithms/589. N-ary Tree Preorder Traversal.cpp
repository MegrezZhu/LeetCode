/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root) return {};
        vector<int> res = {root->val};
        preorder(root, res);
        return res;
    }
    void preorder(Node* root, vector<int> &res) {
        if (!root) return;
        for (auto p : root->children) {
            res.push_back(p->val);
            preorder(p, res);
        }
    }
};