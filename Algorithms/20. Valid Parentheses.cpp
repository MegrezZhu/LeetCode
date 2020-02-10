class Solution {
    bool isLeft(char c) {
        return c == '(' || c == '[' || c == '{'; 
    }
    bool match(char a, char b) {
        return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
    }
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (isLeft(c)) stk.push(c);
            else {
                if (!stk.empty() && match(stk.top(), c)) stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};