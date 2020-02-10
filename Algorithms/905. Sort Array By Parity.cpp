class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int lastEven = -1;
        int n = A.size();
        for (int i = 0; i < n; i++) {
            if (A[i] % 2 == 0) {
                swap(A[lastEven + 1], A[i]);
                lastEven++;
            }
        }
        return A;
    }
};