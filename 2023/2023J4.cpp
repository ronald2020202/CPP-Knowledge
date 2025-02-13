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

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<vector<bool>> t(2, vector<bool>(n, false));
	int temp;

	int p;
	int b = 0;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			if (temp == 0) {
				t[i][j] = false;
			}
			else {
				t[i][j] = true;
				b++;
			}
		}
	}

	p = b * 3;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (t[i][j] && t[i][j + 1]) {
				p-=2;
			}
		}
	}
	for (int j = 0; j < n; j+=2) {
		if (t[0][j] && t[1][j]) {
			p-=2;
		}
	}

	cout << p;

	return 0;
}
