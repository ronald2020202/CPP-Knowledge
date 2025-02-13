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

	vector<string> first(n);
	vector<string> second(n);
	map<string, string> team;

	for (int i = 0; i < n; i++) {
		cin >> first[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> second[i];
		team[first[i]] = second[i];
	}

	for (int i = 0; i < n; i++) {
		if (team[team[first[i]]] != first[i] || team[team[second[i]]] != second[i] || team[first[i]] == first[i] || team[second[i]] == second[i]) {
			cout << "bad" << endl;
			return 0;
		}
	}

	cout << "good";

	return 0;

}