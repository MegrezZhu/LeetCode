class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        stack<int> s;
        int ans = 0;
        for (int x : target) {
            if (!s.empty()) {
                if (s.top() < x) {
                    s.push(x);
                } else {
                    ans += s.top() - x;
                    while (!s.empty() && s.top() >= x) {
                        s.pop();
                    }
                }
            }
            s.push(x);
        }
        ans += s.top();
        return ans;
    }
};