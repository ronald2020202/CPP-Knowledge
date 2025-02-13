#include <iostream>
#include <ios>
#include <limits>
#include <cstring>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <climits>
#include <cmath>
#include <sstream>

using namespace std;

bool ton = false;
int nm = 0;
/*
void recursion(vector<vector<int>>* grid, int m, int n, int x, int y, vector<vector<int>>* visited) {
	for (int i = 0; i < nm; i++) {
		if(grid[x][y] )
	}
}*/

int main() {
	/*
	int m, n;

	cin >> m >> n;

	vector<vector<int>> grid(m + 1, vector<int>(n + 1));
	vector<vector<bool>> visited(m + 1, vector<bool>(n + 1, false));

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
		}
	}
	nm = min(n, m);
	recursion(&grid, m, n, 1, 1, &visited);

	if (ton) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}*/

	string shelf;

	cin >> shelf;
	int l = 0;
	int m = 0;
	int s = 0;
	map<char, int> size;
	int ls = 0;//smalls in large section
	int lm = 0;
	int ml = 0;
	int ms = 0;
	int sl = 0;
	int sm = 0;

	int counter = 0;

	string large;
	string medium;
	string small;

	for (int i = 0; i < shelf.size(); i++) {
		size[shelf[i]]++;
	}
	large = shelf.substr(0, size['L']);
	medium = shelf.substr(size['L'], size['M']);
	small = shelf.substr(size['L'] + size['M'], size['S']);
	/*
	while (1) {
		size_t foundls = large.find('S');
		size_t foundlm = large.find('S');
		size_t foundms = large.find('S');
		size_t foundml = large.find('S');
		size_t foundsl = large.find('S');
		size_t foundsm = large.find('S');
		if (foundls == string::npos && foundlm == string::npos) {
			break;
		}
		if (foundls != string::npos) {
			if (foundsl != string::npos) {
				counter++;
				large[foundls] = 'L';
				small[foundsl] = 'S';
			}
			else {
				counter++;
				large[foundls] = 'L';
				medium[foundml] = 'S';
			}
		}
		if (foundlm != string::npos) {
			if (foundml != string::npos) {
				counter++;
				large[foundlm] = 'L';
				medium[foundml] = 'M';
			}
			else {
				counter++;
				large[foundlm] = 'L';
				small[foundsl] = 'M';
			}
		}
	}*/
	for (int i = 0; i < large.size(); i++) {
		if (large[i] == 'S') {
			size_t foundsl = small.find('L');
			if(foundsl != string::npos) {
				counter++;
				large[i] = 'L';
				small[foundsl] = 'S';
			}
			else {
				counter++;
				large[i] = 'L';
				medium[medium.find('L')] = 'S';
			}
		}
		else if (large[i] == 'M') {
			size_t foundml = medium.find('L');
			if (foundml != string::npos) {
				counter++;
				large[i] = 'L';
				medium[foundml] = 'M';
			}
			else {
				counter++;
				large[i] = 'L';
				small[small.find('L')] = 'M';
			}
		}
	}

	for (int i = 0; i < medium.size(); i++) {
		if (medium[i] == 'S') {
			counter++;
			medium[i] = 'M';
			small[small.find('M')] = 'S';
		}
	}

	cout << counter;

	return 0;
}