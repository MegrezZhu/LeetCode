class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char k = 0;
        int maxD = 0;
        for (int i = 0; i < releaseTimes.size(); i++) {
            char c = keysPressed[i];
            int time = releaseTimes[i] - (i > 0 ? releaseTimes[i - 1] : 0);
            if (time > maxD) {
                maxD = time;
                k = c;
            } else if (time == maxD) {
                k = max(c, k);
            }
        }
        return k;
    }
};