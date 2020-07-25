class Solution {
public:
    int numOfSubarrays(const vector<int>& arr) {
        int numOdd = 0, numEven = 0, ans = 0; // numOdd: number of subarrays ending at pos x
        const int MOD = 1e9 + 7;
        for (int x : arr) {
            if (x % 2 == 0) {
                numEven = (numEven + 1) % MOD;
            } else {
                int tmp = numOdd;
                numOdd = (numEven + 1) % MOD;
                numEven = tmp;
            }
            ans = (ans + numOdd) % MOD;
        }
        
        return ans;
    }
};