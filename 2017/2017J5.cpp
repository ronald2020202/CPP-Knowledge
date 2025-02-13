#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int> l(n);
	int diffHeights = 0;
	int maximum = 0;
	map<int, int> counter;
	vector<int> count(2001, 0);
	vector<int> sums(4001, 0);
	vector<int> different;
	int number;
	for (int i = 0; i < n; i++) {
		cin >> number;
		count[number]++;
	}

	for (int i = 1; i < 2001; i++) {
		sums[i + i] += count[i] / 2;
		for (int j = i + 1; j < 2001; j++) {
			sums[i + j] += min(count[i], count[j]);
		}
	}
	for (int i = 1; i <= 4000; i++) {
		if (sums[i] == maximum) {
			diffHeights++;
		}
		else if (sums[i] > maximum) {
			maximum = sums[i];
			diffHeights = 1;
		}
	}

	cout << maximum << " " << diffHeights;

	return 0;

}