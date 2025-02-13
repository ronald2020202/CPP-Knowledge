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

using namespace std;

int main() {

	int counter;
	int p;
	int c;

	cin >> p;
	cin >> c;

	counter = 50 * p - 10 * c;
	if (p > c) {
		counter += 500;
	}

	cout << counter;

	return 0;
}
