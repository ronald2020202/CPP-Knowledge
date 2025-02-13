#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    
    int m, n, k;
    cin >> m >> n >> k;
    vector<int> r(m, 0);
    vector<int> c(n, 0);

    int rcount = 0;
    int ccount = 0;

    int counter = 0;

    for (int i = 0; i < k; i++) {
        string s;
        int a;
        cin >> s >> a;
        a--;
        if (s == "R") {
            r[a]++;
            if (r[a] % 2 == 1) {
                rcount++;
            }
            else {
                rcount--;
            }
            counter++;
        }
        else {
            c[a]++;
            if (c[a] % 2 == 1) {
                ccount++;
            }
            else {
                ccount--;
            }
        }
    }
    int total = 0;
    total += rcount * (n - ccount);
    total += (m - rcount) * (ccount);/*
    for (int i = 0; i < m; i++) {
        if (r[i] % 2 == 1) {
            total += n - ccount;
        }
        else {
            total += -(n - ccount);
        }
    }*/
    
    cout << total;

    return 0;
}