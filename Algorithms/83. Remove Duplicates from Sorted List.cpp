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
    ListNode* deleteDuplicates(ListNode* head) {
        auto t = head;
        while (t) {
            while (t->next) {
                if (t->next->val != t->val) break;
                t->next = t->next->next;
            }
            t = t->next;
        }
        return head;
    }
};