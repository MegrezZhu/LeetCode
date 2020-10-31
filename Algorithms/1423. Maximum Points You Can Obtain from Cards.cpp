class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        for (int x : cardPoints) sum += x;
        int minn = 1e9;
        for (int i = 0, midSum = 0, last = 0; i < cardPoints.size(); i++) {
            midSum += cardPoints[i];
            if (i - last + 1 > cardPoints.size() - k) {
                midSum -= cardPoints[last];
                last++;
            }
            if (i - last + 1 == cardPoints.size() - k) {
                minn = min(minn, midSum);
            }
        }
        return sum - minn;
    }
};