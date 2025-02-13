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
	vector<int> days(5, 0);

	string temp;
	vector<int> max;
	int maxn = -1;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < 5; j++) {
			if (temp[j] == 'Y') {
				days[j]++;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		if (days[i] > maxn) {
			maxn = days[i];
		}
	}

	for (int i = 0; i < 5; i++) {
		if (days[i] == maxn) {
			max.push_back(i);
		}
	}

	for (int i = 0; i < max.size(); i++) {
		cout << max[i] + 1;
		if (i != max.size() - 1) {
			cout << ",";
		}
	}

	return 0;
}
