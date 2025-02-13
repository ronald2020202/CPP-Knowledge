#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <climits>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> w(n);
	vector<int> e(n);

	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> e[i];
	}
	int max = 0;
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < n; i++) {
		sum1 += w[i];
		sum2 += e[i];
		if (sum1 == sum2) max = i + 1;
	}
	cout << max << endl;
}