class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int x = 0, y = 0, t = 0;
        for (char o : instructions) {
            switch (o) {
                case 'G':
                    x += dx[t];
                    y += dy[t];
                    break;
                case 'L':
                    t = (t + 3) % 4;
                    break;
                case 'R':
                    t = (t + 1) % 4;
                    break;
            }
        }
        return x == 0 && y == 0 || t != 0;
    }
};