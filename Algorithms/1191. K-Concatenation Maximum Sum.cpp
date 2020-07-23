class Solution {
    using LL = long long;
public:
    int kConcatenationMaxSum(const vector<int>& arr, int k) {
        int n = arr.size();
        int maxPrefix = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            maxPrefix = max(maxPrefix, sum);
        }
        int maxSuffix = 0;
        for (int i = n - 1, suffix = 0; i >= 0; i--) {
            suffix += arr[i];
            maxSuffix = max(maxSuffix, suffix);
        }
        int maxMiddleSum = 0;
        for (int i = 0, middleSum = 0; i < n; i++) {
            middleSum = arr[i] + max(0, middleSum);
            maxMiddleSum = max(maxMiddleSum, middleSum);
        }
        
        int ans = maxMiddleSum;
        if (k >= 2) {
            ans = max<int>(ans, (maxPrefix + maxSuffix + (LL(sum) * (k - 2))) % LL(1e9 + 7));
            ans = max(ans, maxPrefix + maxSuffix);
        }
        return ans;
    }
};