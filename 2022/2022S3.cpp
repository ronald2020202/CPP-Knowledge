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
#include <cmath>
#include <math.h>
#include <cerrno>
#include <cfenv>
#include <cstring>
#include <queue>



using namespace std;
#define int long long

pair<int, int> findSmallest(int n, int k, int m) {
    int total = 0;
    int extra = 0;
    while (total < k && extra + 1 <= m) {
        total += n - extra;
        ++extra;
    }
    if (total == k) {
        return { extra, 0 };
    }
    else if (total < k) {
        return { -1, -1 };
    }
    return { extra - 1, k - (total - (n - (extra-1)))};
}

int32_t main() {

    int n, m, k; cin >> n >> m >> k;

    if (k < n || k > n * (n + 1) / 2) {
        cout << -1 << endl;
        return 0;
    }

    pair<int, int> base = findSmallest(n, k, m);
    if (base.first == -1 && base.second == -1) {
        cout << -1 << endl;
        return 0;
    }
    int loop = base.first;
    int remainder = base.second;

    vector<int> piece(n, 0);
    for (int i = 0; i < loop; i++) {
        piece[i] = i + 1;
    }
    int cur = loop + 1;
    for (int i = 0; i < remainder; i++) {
        piece[loop + i] = cur;
        if (++cur > loop + 1) {
            cur = 1;
        }
    }
    vector<int> pattern(loop);
    for (int i = 0; i < loop; i++) {
         pattern[i] = piece[remainder + i];
    }
    int curPattern = 0;
    for (int i = loop + remainder; i < n; i++) {
        piece[i] = pattern[curPattern % loop];
        ++curPattern;
    }

    for (int i = 0; i < n; i++) {
        cout << piece[i] << " ";
    }

    cout << endl;
    
    return 0;
}