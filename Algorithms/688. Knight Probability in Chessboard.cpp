class Solution {
    const vector<int> dx = { -2, -1, 1, 2, 2, 1, -1, -2 };
    const vector<int> dy = { 1, 2, 2, 1, -1, -2, -2, -1 };
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> prob(N, vector<double>(N, .0));
        prob[r][c] = 1.0;
        while (K--) {
            vector<vector<double>> newProb(N, vector<double>(N, .0));
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    for (int d = 0; d < 8; d++) {
                        int x = i + dx[d], y = j + dy[d];
                        if (x >= 0 && y >= 0 && x < N && y < N) {
                            newProb[x][y] += prob[i][j] * 0.125;
                        }
                    }
                }
            }
            prob = move(newProb);
        }
        double probSum = .0;
        for (const auto& row : prob) {
            for (const auto unitProb : row) {
                probSum += unitProb;
            }
        }
        return probSum;
    }
};