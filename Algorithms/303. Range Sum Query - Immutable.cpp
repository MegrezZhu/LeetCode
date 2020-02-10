class NumArray {
public:
    vector<int> s;
    NumArray(vector<int> nums) {
        vector<int> s(nums.size() + 1);
        s[0] = 0;
        for (int i = 0; i < nums.size(); i++) s[i + 1] = s[i] + nums[i];
        this->s = move(s);
    }
    
    int sumRange(int i, int j) {
        return s[j + 1] - s[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */