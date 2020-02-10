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
    int maxDepth(Node* root) {
        if (!root) return 0;
        int maxx = 0;
        for (auto p : root->children) {
            maxx = max(maxx, maxDepth(p));
        }
        return maxx + 1;
    }
};