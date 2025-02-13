#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

long long score(long long p, vector<vector<long long>> &friends) {

    long long counter = 0;

    for (vector<long long> afriend : friends) {
        long long travel = abs(afriend[0] - p) - afriend[2];
        if (travel > 0) {
            counter += travel * afriend[1];
        }
    }
    return counter;
}

int main() {

    // binary search
    
    int n;
    cin >> n;
    vector<vector<long long>> friends(n, vector<long long>(3));
    long long low = LLONG_MAX;
    long long high = 0;

    for (int i = 0; i < n; i++) {
        cin >> friends[i][0] >> friends[i][1] >> friends[i][2];
        if (friends[i][0] < low) {
            low = friends[i][0];
        }
        else if (friends[i][0] > high) {
            high = friends[i][0];
        }
    }

    long long curscore;

    while (low <= high) {
        int mid = (low + high) / 2;
        curscore = score(mid, friends);
        long long nextscore = score(mid + 1, friends);
        long long prevscore = score(mid - 1, friends);
        if (curscore == nextscore || curscore == prevscore) {
            break;
        }
        if (curscore < prevscore && curscore < nextscore) {
            break;
        }
            if (curscore < prevscore) {
            low = mid + 1;
        }
        else if (curscore < nextscore) {
            high = mid - 1;
        }

    }

    cout << curscore;

    return 0;
}