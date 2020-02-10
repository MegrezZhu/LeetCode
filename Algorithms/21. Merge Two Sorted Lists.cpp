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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *fake = new ListNode(0), *head = fake;
        ListNode *p1 = l1, *p2 = l2;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                fake->next = p1;
                p1 = p1->next;
            } else {
                fake->next = p2;
                p2 = p2->next;
            }
            fake = fake->next;
        }
        if (p1) fake->next = p1;
        else fake->next = p2;
        return head->next;
    }
};