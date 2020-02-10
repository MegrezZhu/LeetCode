class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool flag = false;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] < A[i - 1]) {
                flag = true;
                break;
            }
        }
        if (!flag) return true;
        flag = false;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i - 1]) {
                flag = true;
                break;
            }
        }
        return !flag;
    }
};