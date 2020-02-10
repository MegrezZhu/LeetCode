class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		vector<int> great(nums.size());
		list<int> q;
		for (int i = 0; i < nums.size(); i++) {
			while (!q.empty() && nums[q.back()] < nums[i]) {
				great[q.back()] = nums[i];
				q.pop_back();
			}
			q.push_back(i);
		}
		while (!q.empty()) {
			great[q.back()] = -1;
			q.pop_back();
		}

		unordered_map<int, int> mp;
		for (int i = 0; i < great.size(); i++) mp.insert(make_pair(nums[i], great[i]));
		vector<int> res(findNums.size());
		for (int i = 0; i < findNums.size(); i++) res[i] = mp.find(findNums[i])->second;
		return res;
	}
};