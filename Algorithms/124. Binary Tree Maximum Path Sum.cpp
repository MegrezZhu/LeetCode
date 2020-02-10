struct SolNode {
	int val, leftMax, rightMax, midMax, ansMax;
	bool allNeg;
	int maxVal;
	SolNode *left, *right;
	SolNode(TreeNode *node) {
		if (!node) {
			ansMax = midMax = leftMax = rightMax = 0;
			allNeg = true;
			maxVal = -2e9;
			return;
		}
		left = new SolNode(node->left);
		right = new SolNode(node->right);
		val = node->val;
		leftMax = val + max(max(left->leftMax, left->rightMax), 0);
		rightMax = val + max(max(right->leftMax, right->rightMax), 0);
		midMax = leftMax + rightMax - val;
		int t1 = max(left->ansMax, right->ansMax);
		int t2 = max(leftMax, rightMax);
		ansMax = max(max(t1, t2), midMax);
		maxVal = max(max(left->maxVal, right->maxVal), val);
		allNeg = left->allNeg && right->allNeg && val < 0;
	}
};
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	int maxPathSum(TreeNode* root) {
		auto solNode = new SolNode(root);
		return solNode->allNeg ? solNode->maxVal : solNode->ansMax;
	}
};