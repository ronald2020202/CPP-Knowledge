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

int sumH(int start, int end, int c, vector<int>& prefix) {
    int total = 0;
    if (end >= c) {
        total += prefix[c - 1] + prefix[end - c];
    }
    else {
        total += prefix[end];
    }
    if (start != 0) {
        total -= prefix[start - 1];
    }
    return total;
}
int clampZ(int n) {
    return max((int)0, n);
}

int32_t notmain();

int32_t main() {
    //notmain();
    ios::sync_with_stdio(false);

    int n, c; cin >> n >> c;
    vector<int> points(n+1);
    vector<int> prefix(c+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> points[i];
        prefix[points[i]]++;
    }

    for (int i = 1; i < c; i++) {
        prefix[i] += prefix[i - 1];
    }

    long long total = n * (n - 1) * (n - 2) / 6;

    if (c % 2 == 0) {
        for (int i = 0; i < c; i++) {
            int numPoint = (i == 0) ? prefix[0] : prefix[i] - prefix[i - 1];
            int otherHalf = sumH(i + 1, i + c / 2 - 1, c, prefix);
            int tot = numPoint + otherHalf;
            total -= (clampZ(tot * (tot - 1) * (tot - 2) / 6) -
                clampZ(otherHalf * (otherHalf - 1) * (otherHalf - 2) / 6));
        }
        for (int i = 0; i < c / 2; i++) {
            int onePoints = (i == 0) ? prefix[0] : prefix[i] - prefix[i - 1];
            int oppPoints = prefix[i + c / 2] - prefix[i + c / 2 - 1];
            int tot = onePoints + oppPoints;
            total -= onePoints * oppPoints * (n - tot);
            total -= (tot) * (tot - 1) * (tot - 2) / 6;
            total += (onePoints) * (onePoints - 1) * (onePoints - 2) / 6;
            total += (oppPoints) * (oppPoints - 1) * (oppPoints - 2) / 6;
        }
    }
    else {
        for (int i = 0; i < c; i++) {
            int numPoint = (i == 0) ? prefix[0] : prefix[i] - prefix[i - 1];
            int otherHalf = sumH(i + 1, i + c / 2, c, prefix);
            int tot = numPoint + otherHalf;
            total -= (clampZ(tot * (tot - 1) * (tot - 2) / 6) -
                clampZ(otherHalf * (otherHalf - 1) * (otherHalf - 2) / 6));
        }
    }
    

    cout << total << endl;
    
    return 0;
}