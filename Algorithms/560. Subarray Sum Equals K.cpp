class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		map<int, int> mp = { {0,1} };
		int result = 0;
		for (int sum = 0, i = 0; i < nums.size(); i++) {
			sum += nums[i];
			auto it = mp.find(sum - k);
			if (it != mp.end()) result += it->second;
			mp[sum]++;
		}
		return result;
	}
};