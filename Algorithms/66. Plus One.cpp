class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits.back()++;
        for (int i = digits.size() - 1; i > 0; i--) {
            if (digits[i] > 9) {
                digits[i] -= 10;
                digits[i - 1]++;
            }
        }
        if (digits.front() > 9) {
            digits.front() -= 10;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};