#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;
	while (n % 5 != 0) {
		n -= 4;
	}
	while (n % 4 != 0) {
		n -= 5;
	}

	if (n == 0) {
		cout << 1;
		return 0;
	}
	else if (n % 20 != 0) {
		cout << 0;
		return 0;
	}
	
	cout << (n / 20) + 1;

	return 0;
}