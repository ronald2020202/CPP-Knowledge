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
#include <climits>
#include <cmath>
#include <sstream>

using namespace std;

int main() {
	
	int x, y, g;

	string first;
	string second;

	int counter = 0;

	cin >> x;
	vector<pair<string, string>> together(x);
	for (int i = 0; i < x; i++) {
		cin >> together[i].first >> together[i].second;
	}

	cin >> y;
	vector<pair<string, string>> apart(y);
	for (int i = 0; i < y; i++) {
		cin >> apart[i].first >> apart[i].second;
	}

	cin >> g;
	string one;
	string two;
	string three;
	map<string, int> colour;
	for (int i = 0; i < g; i++) {
		cin >> one >> two >> three;
		colour[one] = i;
		colour[two] = i;
		colour[three] = i;
	}

	for (int i = 0; i < x; i++) {
		if (colour[together[i].first] != colour[together[i].second]) {
			counter++;
		}
	}
	for (int i = 0; i < y; i++) {
		if (colour[apart[i].first] == colour[apart[i].second]) {
			counter++;
		}
	}

	cout << counter;
 	
	return 0;
}