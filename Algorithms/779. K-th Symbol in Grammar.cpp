class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1 && K == 1) return 0;
        return K % 2 == 1 ? kthGrammar(N - 1, (K + 1) / 2) : (1 - kthGrammar(N - 1, (K + 1) / 2));
    }
};