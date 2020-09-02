class Trie {
    vector<vector<int>> d;
    vector<bool> flag; // true if the node is a word
public:
    /** Initialize your data structure here. */
    Trie() {
        d.push_back(move(vector<int>(26, -1)));
        flag.push_back(false);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int p = 0;
        for (char c : word) {
            int i = c - 'a';
            if (d[p][i] == -1) {
                d[p][i] = d.size();
                d.push_back(move(vector<int>(26, -1)));
                flag.push_back(false);
            }
            p = d[p][i];
        }
        flag[p] = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(const string &word) {
        int p = 0;
        for (char c : word) {
            int i = c - 'a';
            if (d[p][i] == -1) return false;
            p = d[p][i];
        }
        return flag[p];
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string &prefix) {
        int p = 0;
        for (char c : prefix) {
            int i = c - 'a';
            if (d[p][i] == -1) return false;
            p = d[p][i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */