/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        vector<string> left = wordlist;
        while (left.size() >= 1) {
            auto p = left[rand() % (left.size())];
            int mcount = master.guess(p);
            if (mcount == 6) break;
            vector<string> newleft;
            for (auto &word : left) {
                if (match(word, p) == mcount) {
                    newleft.push_back(word);
                }
            }
            left = newleft;
        }
    }
    
    int match(const string &a, const string &b) {
        int ans = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == b[i]) ans++;
        }
        return ans;
    }
};