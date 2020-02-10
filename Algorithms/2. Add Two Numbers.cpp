/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
        if (!l1 && !l2 && !carry) return NULL;
        auto node = new ListNode((l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry);
        int _carry = node->val / 10;
        node->val %= 10;
        node->next = addTwoNumbers(l1 ? l1->next : NULL, l2 ? l2->next : NULL, _carry);
        return node;
    }
};