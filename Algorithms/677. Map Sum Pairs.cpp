struct TrieNode {
    vector<TrieNode*> next;
    int val, subTreeSum;

    TrieNode(): next(26, NULL), val(0), subTreeSum(0) {}
};

class MapSum {
    TrieNode *root = new TrieNode();
public:
    /** Initialize your data structure here. */
    MapSum() {}
    
    void insert(const string &key, int val) {
        insert(key, val, root, 0);
    }
    
    int insert(const string &key, int val, TrieNode *p, int depth) {
        if (depth == key.length()) {
            int delta = val - p->val;
            p->subTreeSum += delta;
            p->val = val;
            return delta;
        }
        auto &cp = p->next[int(key[depth] - 'a')]; // pointer to child
        if (!cp) {
            cp = new TrieNode();
        }
        int delta = insert(key, val, cp, depth + 1);
        p->subTreeSum += delta;
        return delta;
    }
    
    int sum(const string &prefix) {
        auto p = root;
        for (int i = 0; i < prefix.length(); i++) {
            auto cp = p->next[int(prefix[i] - 'a')];
            if (!cp) return 0;
            p = cp;
        }
        return p->subTreeSum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */