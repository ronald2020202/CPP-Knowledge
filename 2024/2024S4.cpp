#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <set>

using namespace std;

void dfs(map<pair<int, int>, int>& road, vector<char>& colour, vector<bool>& visited, vector<vector<int>>& adj, int n, int cur, int depth) {
    int counter = 0;
    for (int next : adj[cur]) {
        if (!visited[next]) {
            visited[next] = true;
            if (depth % 2 == 0) {
                colour[road[{cur, next}]] = 'B';
            }
            else {
                colour[road[{cur, next}]] = 'R';
            }
            dfs(road, colour, visited, adj, n, next, depth + 1);
        }
    }
}

int main() {
    
    int n, m; cin >> n; cin >> m;
    vector<vector<int>> adj(n+1);
    map<pair<int, int>, int> road;
    vector<char> colour(m, 'G');

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        road[{u, v}] = i;
        road[{v, u}] = i;
    }

    vector<bool> visited(n+1, false);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(road, colour, visited, adj, n, i, 0);
        }
    }

    for (char c : colour) {
        cout << c;
    }
    cout << endl;

    return 0;
}