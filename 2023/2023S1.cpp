#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <string>

using namespace std;

int main()
{

    int n; cin >> n;
    vector<int> mountain(n);
    for (int i = 0; i < n; i++) {
        cin >> mountain[i];
    }
    vector<vector<int>> distance(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            distance[i][j] = distance[j][i] = abs(mountain[i] - mountain[j]);
        }
    }
    vector<int> lengths(n, INT_MAX);
    for (int i = 0; i < n; i++) { // i is midpoint
        int asymmetry = 0;
        for (int j = 0; j <= n / 2; j++) { // odd j + 1 is length of crop / 2
            if (i + j >= n || i - j < 0) { continue; }
            asymmetry += distance[i + j][i - j];
            lengths[2* j] = min(lengths[2*j], asymmetry);
        }
        asymmetry = 0;
        for (int j = 1; j <= n / 2; j++) { // even j + 1 is length of crop / 2
            if (i + j >= n || i - j + 1< 0) { continue; }
            asymmetry += distance[i + j][i - j + 1];
            lengths[2 * j - 1] = min(lengths[2 * j - 1], asymmetry);
        }
    }
    for (int length : lengths) {
        cout << length << " ";
    }

    cout << endl;
    
    return 0;
}