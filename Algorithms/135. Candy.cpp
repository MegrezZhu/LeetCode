class Solution {
public:
    int candy(const vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candy(n, -1);
        for (int i = 0; i < n; i++)
            have(ratings, candy, i);
        int sum = 0;
        for (int x : candy) sum += x;
        return sum;
    }
    int have(const vector<int> &ratings, vector<int> &candy, int id) {
        if (candy[id] != -1) return candy[id];
        int num = 1;
        if (id > 0 && ratings[id] > ratings[id - 1]) num = max(num, have(ratings, candy, id - 1) + 1);
        if (id < ratings.size() - 1 && ratings[id] > ratings[id + 1]) num = max(num, have(ratings, candy, id + 1) + 1);
        candy[id] = num;
        return num;
    }
};