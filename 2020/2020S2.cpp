#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int main() {

    int m, n;
    cin >> m >> n;
    map<int, vector<pair<int, int>>> points;
    map<int, vector<pair<int, int>>> smth;

    vector<vector<int>> room(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            points[a].push_back({ i + 1, j + 1 });
            room[i][j] = a;
            
        }
    }

    queue<pair<int, int>> possible;
    possible.push({ m, n });

    map<pair<int, int>, bool> passed;

    while (!possible.empty()) {

        pair<int, int> cur = possible.front();
        possible.pop();
        if (passed[cur]) {
            continue;
        }
        passed[cur] = true;
        for (pair<int, int> r : points[cur.first * cur.second]) {
            if (r.first == 1 && r.second == 1) {
                cout << "yes";
                return 0;
            }
            possible.push(r);
        }
    }

    cout << "no";

    return 0;
}