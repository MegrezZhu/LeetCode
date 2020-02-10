class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        int sx = 0, sy = 0;
        for (char a : moves) {
            switch (a) {
                case 'U':
                    sx -= 1; break;
                case 'L':
                    sy -= 1; break;
                case 'R':
                    sy += 1; break;
                case 'D':
                    sx += 1; break;
            }
        }
        return sx == sy && sx == 0;
    }
};