class Solution {
public:
    int addDigits(int num) {
    	if (!num) return 0;
    	int t = num % 9;
    	if (!t) t = 9;
    	return t;
    }
};