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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lhead = NULL, *ltail = NULL;
        ListNode *rhead = NULL, *rtail = NULL;
        ListNode *cur = head;
        while (cur) {
            auto next = cur->next;
            if (cur->val < x) {
                if (lhead == NULL) {
                    lhead = ltail = cur;
                } else {
                    ltail->next = cur;
                    ltail = cur;
                }
            } else {
                if (rhead == NULL) {
                    rhead = rtail = cur;
                } else {
                    rtail->next = cur;
                    rtail = cur;
                }
            }
            cur = next;
        }
        if (lhead == NULL) return rhead;
        ltail->next = rhead;
        if (rtail) rtail->next = NULL;
        return lhead;
    }
};