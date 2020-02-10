class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        for (int i = shifts.size() - 1, shift = 0; i >= 0; i--) {
            shift = (shift + shifts[i]) % 26;
            int ch = int(S[i]) + shift;
            if (ch > 'z') ch -= 26;
            S[i] = ch;
        }
        return S;
    }
};