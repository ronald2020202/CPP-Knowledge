#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

int counter = 0;

void recursion(queue<pair<int, int>> q, int t, vector<int> score) {
	if (q.empty()) {
		int biggest = 0;
		bool same = false;
		for (int i = 1; i <= 4; i++) {
			if (score[i] > biggest) {
				biggest = score[i];
				same = false;
			}
			else if (score[i] == biggest) {
				same = true;
			}
		}
		if (biggest == score[t] && !same) {
			counter++;
		}
		return;
	}

	pair<int, int> ront = q.front();
	q.pop();
	score[ront.first] += 3;
	recursion(q, t, score);
	score[ront.first] -= 3;
	score[ront.second] += 3;
	recursion(q, t, score);
	score[ront.second] -= 3;
	score[ront.first]++;
	score[ront.second]++;
	recursion(q, t, score);
}

int main() {

	int t;
	int g;
	cin >> t >> g;
	vector<vector<int>> game(g, vector<int>(5));
	vector<int> score(5, 0);

	int a;
	int b;
	int sa;
	int sb;
	queue<pair<int, int>> q;
	vector<vector<bool>> playedalready(7, vector<bool>(7, false));

	for (int i = 0; i < g; i++) {
		cin >> a >> b >> sa >> sb;
		playedalready[a][b] = true;
		if (sa > sb) {
			score[a] += 3;
		}
		else if (sa < sb) {
			score[b] += 3;
		}
		else if (sa == sb) {
			score[a]++;
			score[b]++;
		}
	}

	for (int i = 1; i < 4; i++) {
		for (int j = i + 1; j <= 4; j++) {
			if (!playedalready[i][j]) {
				q.push({ i, j });
			}
		}
	}

	recursion(q, t, score);

	cout << counter;

	return 0;

}