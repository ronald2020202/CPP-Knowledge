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
    vector<int> tide(n);
    for (int i = 0; i < n; i++) {
        cin >> tide[i];
    }
    sort(tide.begin(), tide.end());
    vector<int> low;
    vector<int> high;

    if (n % 2 == 1) {
        for (int i = 1; i < n / 2 + 1; i++) {
            low.push_back(tide[i]);
        }
        for (int i = n / 2 + 1; i < n; i++) {
            high.push_back(tide[i]);
        }
        for (int i = 0; i < n / 2; i++) {
            cout << low[n / 2 - 1 - i] << " " << high[i] << " ";
        }
        cout << tide[0];
    }
    else {
        for (int i = 0; i < n / 2; i++) {
            low.push_back(tide[i]);
        }
        for (int i = n / 2; i < n; i++) {
            high.push_back(tide[i]);
        }
        for (int i = 0; i < n / 2; i++) {
            cout << low[n / 2 - 1 - i] << " " << high[i] << " ";
        }
    }

    return 0;
}