class Solution {
	int n, m;
	vector<vector<int>> matrix;
	vector<int> row, col; // max rank in the row/col
	map<pair<int, int>, vector<int>> rowMap, colMap; // <row/col, val> to index of id
	vector<pair<int, int>> id;
public:
	vector<vector<int>> matrixRankTransform(vector<vector<int>> mm) {
		matrix = move(mm);
		rowMap.clear();
		colMap.clear();
		id.clear();

		n = matrix.size();
		m = matrix.front().size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				id.push_back({ i, j });
			}
		}
		vector<vector<int>> rank(n, vector<int>(m, -1));
		row = vector<int>(n, -1);
		col = vector<int>(m, -1);

		sort(id.begin(), id.end(), [&](const pair<int, int>& pa, const pair<int, int>& pb) {
			return matrix[pa.first][pa.second] < matrix[pb.first][pb.second];
		});

		for (int i = 0; i < id.size(); i++) {
			auto [x, y] = id[i];
			int val = matrix[x][y];
			rowMap[{x, val}].push_back(i);
			colMap[{y, val}].push_back(i);
		}

		for (const auto& p : id) {
			auto [x, y] = p;
			if (rank[x][y] != -1) continue;
			auto g = group(x, y);
			int rankVal = -1;
			for (auto i : g) {
				auto [tx, ty] = id[i];
				rankVal = max(rankVal, minRank(rank, tx, ty));
			}
			for (auto i : g) {
				auto [tx, ty] = id[i];
				rank[tx][ty] = rankVal;
				row[tx] = max(row[tx], rankVal);
				col[ty] = max(col[ty], rankVal);
			}
		}

		return rank;
	}

	int minRank(vector<vector<int>> &rank, int x, int y) {
		int val = 1;
		val = max(val, row[x] + 1);
		val = max(val, col[y] + 1);
		return val;
	}

	// group of ids, that have the same value and rank
	unordered_set<int> group(int x, int y) {
		unordered_set<int> res;
		int val = matrix[x][y];
		list<pair<bool, int>> li = { {true, x}, {false, y} }; // <T for row, val>
		while (!li.empty()) {
			auto [isRow, ind] = li.front();
			li.pop_front();
			if (isRow) {
				auto it = rowMap.find(make_pair(ind, val));
				if (it != rowMap.end()) {
					for (int ii : it->second) { // ii: index to id
						int i = id[ii].second; // col
						if (res.find(ii) == res.end()) {
							res.insert(ii);
							li.push_back({ false, i });
						}
					}
				}
			}
			else {
				auto it = colMap.find(make_pair(ind, val));
				if (it != colMap.end()) {
					for (int ii : it->second) {
						int i = id[ii].first;
						if (res.find(ii) == res.end()) {
							res.insert(ii);
							li.push_back({ true, i });
						}
					}
				}
			}
		}
		return res;
	}
};