class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        const static int dx[4] = { 0, 1, 0, -1 };
        const static int dy[4] = { 1, 0, -1, 0 };
        
        int n = image.size(), m = image.front().size();
        list<pair<int, int>> li = { { sr, sc } };
        while (!li.empty()) {
            auto f = li.front();
            li.pop_front();
            for (int i = 0; i < 4; i++) {
                int tx = f.first + dx[i], ty = f.second + dy[i];
                if (tx >= 0 && ty >= 0 && tx < n && ty < m && image[tx][ty] == image[f.first][f.second] && image[tx][ty] != newColor) {
                    li.push_back({ tx, ty });
                }
            }
            image[f.first][f.second] = newColor;
        }
        return image;
    }
};