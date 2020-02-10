class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (i < s.length() && !is_vowel(s[i])) i++;
            while (j >= 0 && !is_vowel(s[j])) j--;
            if (i < j && i < s.length() && j >= 0) swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
    bool is_vowel(char a) {
        return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U');
    }
};