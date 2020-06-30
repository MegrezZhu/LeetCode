/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	bool allSame(ListNode* head, ListNode* end = NULL) {
		if (!head) {
			return true;
		}
		int val = head->val;
		for (auto p = head; p != end; p = p->next) {
			if (p->val != val) {
				return false;
			}
		}
		return true;
	}
public:
	ListNode* sortList(ListNode* head, ListNode* end = NULL) {
		if (!head || head == end || allSame(head, end)) {
			return head;
		}
		int pivot = head->val;
		ListNode *p = head->next, *r = head;
		while (p != end) {
			if (p->val <= pivot) {
				r = r->next;
				swap(r->val, p->val);
			}
			p = p->next;
		}
		swap(head->val, r->val);
		sortList(head, r);
		sortList(r->next, end);

		return head;
	}
};