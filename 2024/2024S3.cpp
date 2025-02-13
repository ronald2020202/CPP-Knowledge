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

int main() {
    
    int n; cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    int p1 = 0, p2 = 0;
    int start = 0;

    vector<pair<int, int>> left;
    vector<pair<int, int>> right;

    while (p2 < n && p1 < n) {
        if (b[start] == b[p2]) {
            p2++;
        }
        else {
            if (a[p1] == b[start]) {
                if (p1 < p2 - 1) {
                    right.push_back({ p1, p2 - 1 });
                }
                if (p1 > start) {
                    left.push_back({ start, p1 });
                }
                start = p2;
                p2++;
            }
            p1++;
        }
    }
    if (p1 == n) {
        cout << "NO" << endl;
    }
    else {
        while (p1 < n) {
            if (a[p1] == b[start]) {
                if (p1 < p2 - 1) {
                    right.push_back({ p1, p2 - 1 });
                }
                if (p1 > start) {
                    left.push_back({ start, p1 });
                }
                
                break;
            }
            p1++;
        }
        if (p1 == n) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            cout << left.size() + right.size() << endl;
            for (pair<int, int> swipe : left) {
                cout << "L " << swipe.first << " " << swipe.second << endl;
            }
            for (int i = right.size() - 1; i >= 0; i--) {
                cout << "R " << right[i].first << " " << right[i].second << endl;
            }
        }
    }
        
    return 0;
}