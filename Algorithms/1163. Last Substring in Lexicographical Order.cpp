class Solution {
public:
	string lastSubstring(string s) {
		// KMP like algorithm
		int n = s.size();
		vector<int> fall = { -1, 0 }; // length of pre/post-fix similarity
		int left = 0, right = 0, j = 0; // j: current length of pre/post similarity
		while (right + 1 < n) {
			if (s[right + 1] > s[left]) {
				left = right + 1;
				fall = { -1, 0 };
				right++;
				j = 0;
			}
			else {
				// maintain self-similarity
				int len = right - left + 1;
				if (s[left + j] == s[right + 1]) {
					fall.push_back(j + 1);
					right++;
					j++;
				}
				else if (s[left + j] < s[right + 1]) {
					left = right - j + 1;
					j = fall[j];
					fall.resize(right - left + 2);
				}
				else {
					j = fall[j];
					if (j == -1) {
						right++;
						fall.push_back(0);
						j = 0;
					}
				}
			}
		}
		return s.substr(left);
	}
};