#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <climits>
#include <limits>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <chrono>
#include <ctime> 

using namespace std;

int main() {

    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> ccw(n, vector<int>(n));
    vector<vector<int>> cw(n, vector<int>(n));
    vector<vector<int>> tworot(n, vector<int>(n));
    for (int i = n-1; i >=0; i--) {
        for (int j = 0; j < n; j++) {
            ccw[n-1-i][j] = grid[j][i];
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = n-1; i >=0; i--) {
            cw[j][n-1-i] = grid[i][j];
        }
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            tworot[n-1-i][n-1-j] = grid[i][j];
        }
    }
    if (ccw[0][0] < ccw[0][n - 1] && ccw[0][0] < ccw[n - 1][0]) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << ccw[i][j] << " ";
            }
            cout << endl;
        }
    }
    if (cw[0][0] < cw[0][n - 1] && cw[0][0] < cw[n - 1][0]) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << cw[i][j] << " ";
            }
            cout << endl;
        }
    }
    if (tworot[0][0] < tworot[0][n - 1] && tworot[0][0] < tworot[n - 1][0]) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << tworot[i][j] << " ";
            }
            cout << endl;
        }
    }
    if (grid[0][0] < grid[0][n - 1] && grid[0][0] < grid[n - 1][0]) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}