class Solution {
    bool isUp(char a) {
        return (a >= 'A' && a <= 'Z');
    }
	bool all(const string& word, bool up) {
		for (char a : word) {
			if (up != isUp(a)) return false;
		}
		return true;
	}
public:
	bool detectCapitalUse(string word) {
		if (all(word, false)) return true;
		if (all(word, true)) return true;
		if (isUp(word[0]) && all(word.substr(1), false)) return true;
		return false;
	}
};