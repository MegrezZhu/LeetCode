/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return NULL;
        auto cur = head;
        while (cur) {
            if (cur->child) {
                auto p = flatten(cur->child);
                cur->child = NULL;
                auto next = cur->next;
                
                cur->next = p;
                p->prev = cur;
                while (cur->next) cur = cur->next;
                cur->next = next;
                if (next) next->prev = cur;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};