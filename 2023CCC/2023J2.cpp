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

	map<string, int> peppers;

	peppers.insert(pair<string, int>("Poblano", 1500));
	peppers.insert(pair<string, int>("Mirasol", 6000));
	peppers.insert(pair<string, int>("Serrano", 15500));
	peppers.insert(pair<string, int>("Cayenne", 40000));
	peppers.insert(pair<string, int>("Thai", 75000));
	peppers.insert(pair<string, int>("Habanero", 125000));

	int spice = 0;

	int n;
	cin >> n;

	string temp;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		spice += peppers[temp];
	}

	cout << spice;

	return 0;
}
