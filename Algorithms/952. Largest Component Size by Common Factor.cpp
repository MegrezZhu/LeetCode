class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int n = A.size();
        
        // unordered_map<int, vector<int>> mp;
        unordered_set<int> s;
        vector<vector<int>> factors(n);
        for (int i = 0; i < n; i++) {
            int a = A[i];
            int lim = ceil(sqrt(a));
            for (int p = 2; p <= lim; p++) {
                if (a % p == 0) { // p is a prime factor
                    s.insert(p);
                    factors[i].push_back(p);
                    while (a % p == 0) a /= p;
                }
            }
            if (a > 1) {
                s.insert(a);
                factors[i].push_back(a);
            }
        }
        
        vector<int> primes(s.size());
        int i = 0;
        for (int p : s) primes[i++] = p;
        unordered_map<int, int> ind;
        for (int i = 0; i < primes.size(); i++) ind[primes[i]] = i;
        
        vector<int> f(primes.size(), -1);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < factors[i].size(); j++) {
                unions(f, ind[factors[i][0]], ind[factors[i][j]]);
            }
        }
        unordered_map<int, int> count;
        for (auto &factor : factors) {
            if (factor.empty()) continue;
            int p = factor.front();
            int group = find(f, ind[p]);
            count[group]++;
        }
        int ans = 0;
        for (auto &p : count) {
            ans = max(ans, p.second);
        }
        
        return ans;
    }
private:
    void unions(vector<int> &f, int a, int b) {
        int pa = find(f, a), pb = find(f, b);
        if (pa != pb) {
            f[pb] += f[pa];
            f[pa] = pb;
        }
    }
    int find(vector<int> &f, int a) {
        int p = a;
        while (f[p] >= 0) p = f[p];
        int q = a;
        while (f[q] >= 0) {
            int parent = f[q];
            f[q] = p;
            q = parent;
        }
        return p;
    }
};
