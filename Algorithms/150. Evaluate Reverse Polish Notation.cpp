class Solution {
    pair<int, int> pop2(stack<int> &st) {
        int b = st.top();
        st.pop();
        int a = st.top();
        st.pop();
        return { a, b };
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const auto &o : tokens) {
            if (o == "+") {
                auto p = pop2(st);
                st.push(p.first + p.second);
            } else if (o == "-") {
                auto p = pop2(st);
                st.push(p.first - p.second);
            } else if (o == "*") {
                auto p = pop2(st);
                st.push(p.first * p.second);
            } else if (o == "/") {
                auto p = pop2(st);
                st.push(p.first / p.second);
            } else {
                st.push(stoi(o));
            }            
        }
        return st.top();
    }
};