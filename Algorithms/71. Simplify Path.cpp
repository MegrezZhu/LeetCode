class Solution {
public:
    string simplifyPath(string path) {
        path += '/';
        stack<string> p;
        for (int last = 0, i = 0; i < path.length(); i++) {
            if (path[i] == '/') {
                if (i != last) {
                    auto c = path.substr(last, i - last);
                    if (c == "."); // nothing
                    else if (c == "..") {
                        if (!p.empty()) p.pop();
                    } else p.push(c);                    
                }
                last = i + 1;
            }
        }   
        string res;
        while (!p.empty()) {
            auto c = p.top();
            p.pop();
            res = '/' + c + res;
        }
        return res.empty() ? "/" : res;
    } 
};