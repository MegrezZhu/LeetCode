class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        
        int left = P, score = 0;
        int i = -1, j = n;
        while (i + 1 < j) {
            if (tokens[i + 1] > left) {
                if (score > 0) {
                    left += tokens[--j];
                    score--;
                } else {
                    break;
                }
            }
            left -= tokens[++i];
            score++;
        }
        
        return max(score, 0);
    }
};