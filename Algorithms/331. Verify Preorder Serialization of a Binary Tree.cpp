class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<int> s;
        size_t i = 0, j = 0;
        const int NULL_NODE = 0;
        const int NODE = 1;
        while (i < preorder.size()) {
            if (j == preorder.size() || preorder[j] == ',') {
                if (i + 1 == j && preorder[i] == '#') { // null node
                    s.push_back(NULL_NODE);                    
                } else {
                    s.push_back(NODE);
                }
                i = j + 1;
                while (s.size() >= 3) { // shrink
                    size_t p = s.size() - 3;
                    if (s[p] == NODE && s[p + 1] == NULL_NODE && s[p + 2] == NULL_NODE) {
                        s.pop_back();
                        s.pop_back();
                        s.back() = NULL_NODE;
                    } else {
                        break;
                    }
                }
            }
            j++;
        }        
        return (s.size() == 1 && s.back() == NULL_NODE);
    }
};