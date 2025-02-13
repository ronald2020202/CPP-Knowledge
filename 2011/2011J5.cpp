#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

int recursion(vector<vector<int>> adj, int mark) {
	if (adj[mark].empty()) {
		return 1;
	}
	int possible = 1;
	for (int i = 0; i < adj[mark].size(); i++) {
		possible *= (1 + recursion(adj, adj[mark][i]));
	}
	return possible;
}

int main() {
	
	int n;
	int invite;
	cin >> n;
	vector<vector<int>> adj(n + 1);

	for (int i = 1; i < n; i++) {
		cin >> invite;
		adj[invite].push_back(i);
	}

	int total = recursion(adj, n);

	cout << total;

	return 0;

}