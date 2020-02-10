class Solution {
	int req[256], meet[256];
public:
	string minWindow(string s, string t) {
		if (s.length() < t.length()) return "";
		memset(req, 0, 256);
		memset(meet, 0, 256);
		int unMeet = 0;
		for (char c : t) {
			if (!req[c]) unMeet++;
			req[c]++;
		}
		int minLen = 2e9, minPos;
		bool ok = false;
		for (int i = 0, pos = 0; i < s.length(); i++) {
			meet[s[i]]++;
			if (meet[s[i]] == req[s[i]]) {
				// just meet
				unMeet--;
				if (!unMeet) ok = true;
			}
			while (meet[s[pos]] > req[s[pos]]) meet[s[pos++]]--;
			if (ok && i - pos + 1 < minLen) {
				minLen = i - pos + 1;
				minPos = pos;
			}
		}

		return ok ? s.substr(minPos, minLen) : "";
	}
};