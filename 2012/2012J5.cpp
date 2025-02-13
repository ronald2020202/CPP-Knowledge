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

	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}

		vector<stack<int>> table(n);
		map<vector<stack<int>>, bool> visited;

		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			table[i].push(temp);
		}

		queue<pair<vector<stack<int>>, int>> bfs;

		bfs.push({ table, 0 });
		visited[table] = true;

		bool gotten = false;

		while (!bfs.empty()) {
			vector<stack<int>> front = bfs.front().first;
			int step = bfs.front().second;
			vector<stack<int>> temp = front;
			bfs.pop();

			bool check = true;
			for (int i = 0; i < n; i++) {
				if (front[i].empty() || front[i].top() != i + 1) {
					check = false;
				}
			}
			if (check) {
				cout << step << endl;
				gotten = true;
				break;
			}
			
			for (int i = 0; i < n; i++) {
				if (i > 0) {
					if (!front[i].empty() && front[i - 1].empty() || !front[i].empty() && front[i - 1].top() >= front[i].top()) {
						front[i - 1].push(front[i].top());
						front[i].pop();
						if (!visited[front]) {
							bfs.push({ front, step + 1 });
							visited[front] = true;
						}
						front = temp;
					}
				}
				if (i < n - 1) {
					if (!front[i].empty() && front[i + 1].empty() || !front[i].empty() && front[i + 1].top() >= front[i].top()) {
						front[i + 1].push(front[i].top());
						front[i].pop();
						if (!visited[front]) {
							bfs.push({ front, step + 1 });
							visited[front] = true;
						}
						front = temp;
					}
				}
			}
		}
		if (!gotten) {
			cout << "IMPOSSIBLE" << endl;
		}
	}

	return 0;

}