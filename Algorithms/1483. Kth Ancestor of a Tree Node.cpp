class TreeAncestor {
    vector<vector<int>> link;  // link[i][j] -> 2^j-th ancestor of node i
public:
    TreeAncestor(int n, vector<int>& parent): link(n) {        
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                link[i].push_back(parent[i]);
            }
        }

        int lvl = 1;
        while (true) {
            bool cont = false;
            
            for (int i = 0; i < n; i++) {
                if (lvl - 1 < link[i].size()) {
                    int p1 = link[i][lvl - 1];
                    if (lvl - 1 < link[p1].size()) {
                        int p2 = link[p1][lvl - 1];
                        link[i].push_back(p2);
                        cont = true;
                    }
                }
            }
            
            if (!cont) {
                break;
            }
            lvl += 1;
        }
    }
    
    int getKthAncestor(int node, int k) {
        if (k == 0) {
            return node;
        }
        int lvl = log(k) / log(2);
        int exp = pow(2, lvl);
        if (lvl < link[node].size()) {
            return getKthAncestor(link[node][lvl], k - exp);
        } else {
            return -1;
        }
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */