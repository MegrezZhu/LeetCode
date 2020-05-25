class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int n = light.size();
        vector<int> status(n, 0); // 0: off, 1: on, 2: on & blue
        int white = 0, ans = 0;
        for (int x : light) {
            x--; // index starts with 1
            status[x] = 1;
            white++;
            
            while (x < n && (x == 0 || status[x - 1] == 2) && status[x] != 0) {
                if (status[x] == 1) {
                    status[x] = 2;
                    white--;
                    if (white == 0) ans++;
                }                
                x++;
            }
        }
        return ans;
    }
};