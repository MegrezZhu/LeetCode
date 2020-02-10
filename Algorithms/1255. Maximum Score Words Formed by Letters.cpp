class Solution {
public:
	int maxScoreWords(const vector<string>& words, const vector<char>& letters, const vector<int>& score) {
		vector<int> letterCount(26, 0);
		vector<vector<int>> wordCount(words.size(), vector<int>(26, 0));
		vector<int> wordScore(words.size(), 0);
		for (auto c : letters) letterCount[c - 'a']++;
		for (int i = 0; i < words.size(); i++) {
			const auto& s = words[i];
			for (auto c : s) {
				wordCount[i][c - 'a']++;
				wordScore[i] += score[c - 'a'];
			}
		}

		return dfs(wordCount, letterCount, wordScore, 0, 0);
	}

	int dfs(vector<vector<int>>& words, vector<int>& letters, const vector<int>& scores, int L, int score) {
		// take or not take
		if (L >= words.size()) {
			return score;
		}

		int ans = 0;

		if (enough(words[L], letters)) {
			sub(words[L], letters);
			ans = max(ans, dfs(words, letters, scores, L + 1, score + scores[L]));
			add(words[L], letters);
		}
		ans = max(ans, dfs(words, letters, scores, L + 1, score));

		return ans;
	}

	bool enough(const vector<int>& word, const vector<int>& letters) {
		for (int i = 0; i < 26; i++) {
			if (word[i] > letters[i]) return false;
		}
		return true;
	}

	void sub(const vector<int>& word, vector<int>& letters) {
		for (int i = 0; i < 26; i++) {
			letters[i] -= word[i];
		}
	}

	void add(const vector<int>& word, vector<int>& letters) {
		for (int i = 0; i < 26; i++) {
			letters[i] += word[i];
		}
	}
};