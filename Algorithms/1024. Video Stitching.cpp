class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        int num = 0, right = 0;
        int i = 0;
        while (i < clips.size() && right < T) {
            int maxr = right;
            while (i < clips.size() && clips[i][0] <= right) {
                maxr = max(maxr, clips[i][1]);
                i++;
            }
            if (maxr > right) {
                right = maxr;
                num++;
            } else {
                break;
            }
        }
        return right >= T ? num : -1;
    }
};