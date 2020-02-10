/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    pair<ListNode*, ListNode*> reverse(ListNode *head) { // return <head, tail>
        if (!head || !head->next) return {head, head};
        auto p = reverse(head->next);
        p.second->next = head;
        head->next = NULL;
        return {p.first, head};
    }
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(head).first;
    }
};