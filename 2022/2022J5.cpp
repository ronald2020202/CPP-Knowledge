#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int search(int t, int n, vector<pair<int, int>> tree, int row, int column) {
	vector< pair<int, int>> candidates;
	for (pair<int, int> curtree : tree) {
		if (curtree.first > row && curtree.second > column) {
			candidates.push_back(curtree);
		}
	}
	if (candidates.size() == 0) {
		return min(n - row, n - column);
	}
	int most = 0;
	for (pair<int, int> border : candidates) {
		//bottom or right
		int bottom = border.first;
		int right = n + 1;
		for (pair<int, int> border1 : candidates) {
			if (border1.first >= bottom) {
				continue;
			}
			else {
				right = min(border1.second, right);
			}
		}
		int square = min(bottom - row - 1, right - column - 1);
		most = max(most, square);
		bottom = n + 1;
		right = border.second;
		for (pair<int, int> border1 : candidates) {
			if (border1.second >= right) {
				continue;
			}
			else {
				bottom = min(border1.first, bottom);
			}
		}
		square = min(bottom - row - 1, right - column - 1);
		most = max(most, square);
	}
	return most;
}

int main() {
	int n;
	int t;
	cin >> n >> t;
	vector<pair<int, int>> tree(t);
	set<int> rows = { 0 };
	set<int> columns = { 0 };
	int most = 0;


	for (int i = 0; i < t; i++) {
		cin >> tree[i].first >> tree[i].second;
		rows.insert(tree[i].first);
		columns.insert(tree[i].second);
	}

	for (int row:rows) {
		for (int column:columns) {
			int start = search(t, n, tree, row, column);
			most = max(most, start);
		}
	}

	cout << most;

	return 0;
}