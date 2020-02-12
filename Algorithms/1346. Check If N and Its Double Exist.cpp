class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s(arr.cbegin(), arr.cend());
        int zero = 0;
        for (int i : arr) {
            if (i == 0) zero++;
        }
        if (zero > 1) return true;
        for (int i : s) {
            if (i == 0) zero++;
            else if (s.find(i * 2) != s.end()) return true;
        }
        return false;
    }
};