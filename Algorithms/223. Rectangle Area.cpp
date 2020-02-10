class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sa = abs((A - C) * (B - D)), sb = abs((E - G) * (F - H));
        if (A >= G || C <= E) return sa + sb;
        if (B >= H || D <= F) return sa + sb;
        int w = min(abs(C - E), abs(G - A)), h = min(abs(B - H), abs(F - D));
        w = min(w, min(C - A, G - E));
        h = min(h, min(D - B, H - F));
        return sa + sb - h * w;
    }
};