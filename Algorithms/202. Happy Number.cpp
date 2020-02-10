
#include<set>

using namespace std;

class Solution{
public:
	int cal(int a) {
		int s = 0;
		while (a) {
			s += (a % 10)*(a % 10);
			a /= 10;
		}
		return s;
	}

	bool isHappy(int n) {
		set<int> st;
		while (n != 1) {
			n = cal(n);
			if (!st.insert(n).second) return false;
		}
		return true;
	}
};