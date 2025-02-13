#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	int q;
	int n = 0;
	int total = 0;

	cin >> q >> n;

	vector<int> d(n);
	vector<int> p(n);

	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	sort(d.begin(), d.end());
	sort(p.begin(), p.end());

	if (q == 1) {
		for (int i = 0; i < n; i++) {
			total += max(d[i], p[i]);
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			total += max(d[i], p[n - 1 - i]);
		}
	}

	cout << total;

	return 0;
}