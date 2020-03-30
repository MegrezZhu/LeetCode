class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i + 1 < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPred(words[i], words[j])) {
                    adj[i].push_back(j);
                } else if (isPred(words[j], words[i])) {
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int> res(n, -1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, len(adj, res, i));
        }
        
        return ans;
    }
    
    int len(const vector<vector<int>> &adj, vector<int> &res, int node) {
        if (res[node] != -1) return res[node];
        
        int maxx = 0;
        for (int next : adj[node]) {
            maxx = max(maxx, len(adj, res, next));
        }
        
        res[node] = maxx + 1;
        return maxx + 1;
    }
    
    bool isPred(const string &a, const string &b) {
        if (a.length() + 1 != b.length()) return false;
        
        bool added = false;
        for (int i = 0, j = 0; i < a.length(); i++, j++) {
            if (a[i] == b[j]) continue;
            else if (!added) {
                added = true;
                j += 1;
                if (a[i] == b[j]) continue;
                else return false;
            } else return false;
        }
        
        return true;
    }
};