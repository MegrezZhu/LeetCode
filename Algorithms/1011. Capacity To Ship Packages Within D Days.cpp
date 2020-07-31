class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int weightSum = 0;
        for (int w : weights) weightSum += w;
        
        int l = 1, r = weightSum;
        while (l < r) {
            int mid = (l + r) / 2;
            if (daysToShip(weights, mid) <= D) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    
    int daysToShip(const vector<int>& weights, int cap) {
        int count = 0, load = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] > cap) return 1e9;
            if (load + weights[i] > cap) {
                count++;
                load = 0;
            }
            load += weights[i];
        }
        if (load != 0) count++;
        return count;
    }
};