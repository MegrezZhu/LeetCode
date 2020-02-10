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
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val) head = head->next;
        if (head) {
            auto last = head, p = head->next;
            while (p) {
                if (p->val == val) {
                    last->next = p->next;
                    p = p->next;
                } else {
                    last = p;
                    p = p->next;
                }
            }
        }
        return head;
    }
};