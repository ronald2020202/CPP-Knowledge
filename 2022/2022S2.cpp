#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>

using namespace std;

int main() {

	int x, y, g;
	cin >> x;
	map<string, vector<string>> together;
	for (int i = 0; i < x; i++) {
		string temp;
		string temp2;
		cin >> temp >> temp2;
		together[temp].push_back(temp2);
		together[temp2].push_back(temp);
	}
	cin >> y;
	map<string, vector<string>> apart;
	for (int i = 0; i < y; i++) {
		string temp;
		string temp2;
		cin >> temp >> temp2;
		apart[temp].push_back(temp2);
		apart[temp2].push_back(temp);
	}
	cin >> g;
	int counter = x;
	map<string, string> groups;
	for (int i = 0; i < g; i++) {
		string one, two, three;
		cin >> one >> two >> three;
		if (find(together[one].begin(), together[one].end(), two) != together[one].end()) {
			counter--;
		}
		if (find(together[one].begin(), together[one].end(), three) != together[one].end()) {
			counter--;
		}
		if (find(together[two].begin(), together[two].end(), three) != together[two].end()) {
			counter--;
		}
		if (find(apart[one].begin(), apart[one].end(), two) != apart[one].end()) {
			counter++;
		}
		if (find(apart[one].begin(), apart[one].end(), three) != apart[one].end()) {
			counter++;
		}
		if (find(apart[two].begin(), apart[two].end(), three) != apart[two].end()) {
			counter++;
		}
	}

	cout << counter;

	return 0;
}