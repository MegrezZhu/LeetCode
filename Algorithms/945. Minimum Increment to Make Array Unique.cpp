class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.empty()) return 0;
        sort(A.begin(), A.end());
        list<int> wait;
        int ans = 0;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] == A[i - 1]) wait.push_back(A[i]);
            else {
                int p = A[i - 1] + 1;
                while (p != A[i] && !wait.empty()) {
                    int x = wait.front();
                    wait.pop_front();
                    ans += p - x;
                    p++;
                }
            }
        }
        int p = A.back() + 1;
        while (!wait.empty()) {
            int x = wait.front();
            wait.pop_front();
            ans += p - x;
            p++;
        }
        return ans;
    }
};