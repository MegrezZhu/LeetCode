class Solution {
	int length(ListNode* root) {
		int len = 0;
		while (root) {
			len++;
			root = root->next;
		}
		return len;
	}

	pair<ListNode*, ListNode*> split(ListNode* root, int len) {
		if (len == 0) return { NULL, NULL };
		auto st = root;
		while (--len) root = root->next;
		auto p = root->next;
		root->next = NULL;
		return { st, p };
	}
public:
	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		vector<ListNode*> res;
		int len = length(root);
		int avg = len / k, left = len % k;
		for (int i = 0; i < k; i++) {
			int sLen = avg + (i < left ? 1 : 0);
			auto p = split(root, sLen);
			res.push_back(p.first);
			root = p.second;
		}
		return res;
	}
};