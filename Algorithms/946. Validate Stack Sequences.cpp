class Solution {
public:
    bool validateStackSequences(const vector<int>& pushed, const vector<int>& popped) {
        int i = 0, n = pushed.size();
        stack<int> s;
        for (int j = 0; j < n; j++) {
            while (i < n && (s.empty() || s.top() != popped[j])) {
                s.push(pushed[i]);
                i++;
            }
            if (s.top() == popped[j]) {
                s.pop();
            } else {
                return false;
            }            
        }
        return true;
    }
};