class Solution {
public:
	bool isPossible(const vector<int>& target) {
		set<int> st; // val -> ind

		long long sum = 0;
		for (int i = 0; i < target.size(); i++) {
			sum += target[i];
			if (target[i] != 1) {
				if (st.find(target[i]) != st.end()) {
					return false;
				}
				else {
					st.insert(target[i]);
				}
			}
		}

		while (!st.empty()) {
			int largest = *st.rbegin();
			int restSum = sum - largest;
			if (restSum <= 0 || largest <= restSum) {
				return false;
			}
			int newVal = largest - restSum;
			if (restSum == 1) {
				newVal = 1;
			}
			else {
				newVal %= restSum;
			}
			sum -= largest - newVal;
			st.erase(largest);
			if (newVal > 1) {
				if (st.find(newVal) == st.end()) {
					st.insert(newVal);
				}
				else {
					return false;
				}
			}
			else if (newVal != 1) {
				return false;
			}
		}

		return true;
	}
};