class Solution {
public:
	string numberToWords(int num) {
		if (num == 0) return "Zero";

		int billion = num / 1000000000, million = num / 1000000 % 1000, kilo = num / 1000 % 1000, one = num % 1000;
		vector<string> res;
		if (billion > 0) {
			auto res1 = quant(billion);
			res.insert(res.end(), make_move_iterator(res1.begin()), make_move_iterator(res1.end()));
			res.push_back("Billion");
		}
		if (million > 0) {
			auto res1 = quant(million);
			res.insert(res.end(), make_move_iterator(res1.begin()), make_move_iterator(res1.end()));
			res.push_back("Million");
		}
		if (kilo > 0) {
			auto res1 = quant(kilo);
			res.insert(res.end(), make_move_iterator(res1.begin()), make_move_iterator(res1.end()));
			res.push_back("Thousand");
		}
		auto res1 = quant(one);
		res.insert(res.end(), make_move_iterator(res1.begin()), make_move_iterator(res1.end()));

		ostringstream ss;
		copy(res.begin(), res.end(), ostream_iterator<string>(ss, " "));
		auto str = ss.str();
		return str.substr(0, str.length() - 1);
	}

	vector<string> quant(int num) { // less than 1000
		const static vector<string> ones = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten" };
		const static vector<string> tens = { "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
		const static vector<string> teens = { "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
		if (num >= 1000) return { "ERR!" };

		vector<string> res;
		if (num >= 100) {
			res.push_back(ones[num / 100 - 1]);
			res.push_back("Hundred");
		}
		num %= 100;

		if (num != 0) {
			if (num < 20) {
				if (num <= 10) res.push_back(ones[num - 1]);
				else res.push_back(teens[num - 11]);
			}
			else {
				res.push_back(tens[num / 10 - 1]);
				if (num % 10 != 0) res.push_back(ones[num % 10 - 1]);
			}
		}
		return res;
	}
};