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
	stack<int> s;
	for (int i = 0; i < n; i++) {
		int next; cin >> next;
		if (next == 0) {
			s.pop();
		}
		else {
			s.push(next);
		}
	}
	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum << endl;
}