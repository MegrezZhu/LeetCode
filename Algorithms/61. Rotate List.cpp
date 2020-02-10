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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        auto tail = head;
        int len = 1;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        
        k = len - (k % len);
        while (k--) {
            tail->next = head;
            auto tmp = head->next;
            head->next = NULL;
            tail = head;
            head = tmp;
        }
        return head;
    }
};