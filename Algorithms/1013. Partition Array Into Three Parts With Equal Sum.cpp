class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for (int a : A) sum += a;
        if (sum % 3) return false;
        int target = sum / 3;
        int count = 0;
        for (int i = 0, s = 0; i < A.size(); i++) {
            s += A[i];
            if (s == target) {
                s = 0;
                count++;
            }
        }
        return count == 3;
    }
};