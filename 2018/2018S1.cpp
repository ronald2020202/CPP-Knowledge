#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <climits>
#include <limits>
#include <algorithm>
#include <stack>
#include <iomanip>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> villages(n);
	for (int i = 0; i < n; i++) {
		cin >> villages[i];
	}
	sort(villages.begin(), villages.end());
	double minD = numeric_limits<double>::max();
	for (int i = 1; i < n - 1; i++) {
		double size = (villages[i+1] - villages[i - 1]) / 2.0;
		minD = min(minD, size);
	}
	
	cout << fixed << setprecision(1) << minD << endl;
}