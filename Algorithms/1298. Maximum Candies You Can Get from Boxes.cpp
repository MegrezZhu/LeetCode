class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, const vector<vector<int>>& keys, const vector<vector<int>>& containedBoxes, const vector<int>& initialBoxes) {
        int n = status.size(), sum = 0;
        list<int> boxes;
        vector<bool> contained(n, true);
        
        for (int box : initialBoxes) {
            contained[box] = false;
            if (status[box] == 1) {
                boxes.push_back(box);
            }
        }
        
        while (!boxes.empty()) {
            auto id = boxes.front();
            boxes.pop_front();
            sum += candies[id];
            
            for (auto box : containedBoxes[id]) {
                contained[box] = false;
                if (status[box] == 1) { // not locked
                    boxes.push_back(box);
                }
            }
            
            for (auto key : keys[id]) {
                if (status[key] == 0) {
                    status[key] = 1; 
                    if (!contained[key]) {
                        boxes.push_back(key);
                    }
                }
            }
        }
        
        return sum;
    }
};