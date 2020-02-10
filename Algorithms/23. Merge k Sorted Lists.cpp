/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <algorithm>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto head = new ListNode(0), tail = head;
        vector<ListNode*> heap;
        for (auto it = lists.begin(); it != lists.end(); it++) {
            auto node = *it;
            if (node) heap.push_back(node);
        }
        auto comp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        make_heap(heap.begin(), heap.end(), comp);
        while (heap.size()) {
            pop_heap(heap.begin(), heap.end(), comp);
            ListNode* selected = heap.back();
            heap.pop_back();
            tail = tail->next = new ListNode(selected->val);
            if (selected->next) {
                heap.push_back(selected->next);
                push_heap(heap.begin(), heap.end(), comp);
            }
        }
        return head->next;
    }
};