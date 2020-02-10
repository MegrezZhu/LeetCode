class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int> s;
        vector<int> res;
        for (int x : asteroids) {
            if (x < 0) {
                bool broken = false;
                while (!broken && !s.empty()) {
                    if (s.back() < abs(x)) s.pop_back();
                    else if (s.back() == abs(x)) {
                        s.pop_back();
                        broken = true;
                    } else {
                        broken = true;
                    }
                }
                if (!broken) res.push_back(x);
            } else {
                s.push_back(x);
            }
        }
        while (!s.empty()) {
            res.push_back(s.front());
            s.pop_front();
        }
        return res;
    }
};