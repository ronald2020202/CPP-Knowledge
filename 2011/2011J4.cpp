#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

int main() {

	map<pair<int, int>, bool> map;
	map[{0, -1}] = true;
	map[{0, -2}] = true;
	map[{0, -3}] = true;
	map[{1, -3}] = true;
	map[{2, -3}] = true;
	map[{3, -3}] = true;
	map[{3, -4}] = true;
	map[{3, -5}] = true;
	map[{4, -5}] = true;
	map[{5, -5}] = true;
	map[{5, -4}] = true;
	map[{5, -3}] = true;
	map[{6, -3}] = true;
	map[{7, -3}] = true;
	map[{7, -4}] = true;
	map[{7, -5}] = true;
	map[{7, -6}] = true;
	map[{7, -7}] = true;
	map[{6, -7}] = true;
	map[{5, -7}] = true;
	map[{4, -7}] = true;
	map[{3, -7}] = true;
	map[{2, -7}] = true;
	map[{1, -7}] = true;
	map[{0, -7}] = true;
	map[{-1, -7}] = true;
	map[{-1, -6}] = true;
	map[{-1, -5}] = true;

	int row = -1;
	int column = -5;
	char dir;
	int val;

	while (1) {
		cin >> dir >> val;
		bool danger = false;
		if (dir == 'q') {
			break;
		}
		else if (dir == 'l') {
			for (int i = 0; i < val; i++) {
				row--;
				if (map[{row, column}]) {
					danger = true;
				}
				map[{row, column}] = true;
			}
		}
		else if (dir == 'r') {
			for (int i = 0; i < val; i++) {
				row++;
				if (map[{row, column}]) {
					danger = true;
				}
				map[{row, column}] = true;
			}
		}
		else if (dir == 'd') {
			for (int i = 0; i < val; i++) {
				column--;
				if (map[{row, column}]) {
					danger = true;
				}
				map[{row, column}] = true;
			}
		}
		else if (dir == 'u') {
			for (int i = 0; i < val; i++) {
				column++;
				if (map[{row, column}]) {
					danger = true;
				}
				map[{row, column}] = true;
			}
		}
		cout << row << " " << column << " ";
		if (danger) {
			cout << "DANGER";
			break;
		}
		else {
			cout << "safe";
		}
		cout << endl;
	}

	return 0;

}