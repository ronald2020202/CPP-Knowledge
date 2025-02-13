#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

vector<vector<vector<int>>> visited;

int recursion(int n, int k, int s) {

	if (visited[n][k][s] != 0) {
		return visited[n][k][s];
	}
	else if (n == k || k == 1) {
		return 1;
	}
	else if (n < k) {
		return 0;
	}

	int output = 0;
	for (int i = s; i <= n / k; i++) {
		output += recursion(n - i, k - 1, i);
		
	}
	visited[n][k][s] = output;
	return output;
}

int main() {

	int n;
	int k;
	cin >> n >> k;

	visited = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(k + 1, vector<int>(n + 1, 0)));

	int counter = recursion(n, k, 1);

	cout << counter;

	return 0;

}