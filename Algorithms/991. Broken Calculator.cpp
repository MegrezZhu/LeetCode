class Solution {
public:
    int brokenCalc(int X, int Y) {
        if (X >= Y) return X - Y;
        return brokenCalc(X, (Y + 1) / 2) + 1 + (Y % 2);
    }
};