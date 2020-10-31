// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int v = rand5();
        int v1 = rand2();
        return v1 ? v + 5 : v;
    }
    
    int rand5() {
        while (true) {
            int v = rand7();
            if (v <= 5) return v;
        }
    }
    
    int rand2() {
        while (true) {
            int v = rand7();
            if (v <= 6) return v % 2;
        }
    }
};