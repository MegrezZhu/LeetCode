/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     RandomListNode *next, *random;
*     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
* };
*/

#include<cstdlib>
#include<map>

using namespace std;

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		map<RandomListNode*, RandomListNode*> mp;  //old -> new
		auto p = head;
		RandomListNode *res = NULL, *last = NULL;
		while (p) {
			if (!res) {
				res = new RandomListNode(p->label);
				last = res;
			}
			else {
				last->next = new RandomListNode(p->label);
				last = last->next;
			}
			mp.emplace(p, last);
			p = p->next;
		}
		p = head;
		auto p1 = res;
		while (p) {
			if (p->random) {
				p1->random = mp.find(p->random)->second;
			}
			p1 = p1->next;
			p = p->next;
		}
		return res;
	}
};