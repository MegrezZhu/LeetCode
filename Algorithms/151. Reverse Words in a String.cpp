class Solution {
public:
    string reverseWords(string s) {
		int pos = s.length() - 1;
        bool first = true;
        string res;
		while (pos >= 0) {
			if (isblank(s[pos])) pos--;
			else {
				int left = pos;
				while (left > 0 && !isblank(s[left - 1])) left--;
                if (!first) {
                    res += ' ';
                }
                first = false;
				for (int i = left; i <= pos; i++) res += s[i];
				pos = left - 1;
			}
		}
        return res;
	}
};
