#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

int main() {
	
	int n;
	vector<int> change;

	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}
		vector<int> change(n);
		int before;
		int after;
		if (n == 1) {
			change[0] = 0;
		}
		cin >> before;
		for (int i = 0; i < n - 1; i++) {
			cin >> after;
			change[i] = after - before;
			before = after;
		}
		bool found = false;
		for (int i = 1; i < n; i++) {
			bool good = true;
			for (int j = i; j < change.size() - 1; j++) {
				if (change[j] != change[j % i]) {
					good = false;
					break;
				}
			}
			if (good) {
				cout << i << endl;
				found = true;
				break;
			}
		}
		if (!found) {
			cout << n - 1 << endl;
		}
  	}

	return 0;

}