#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
 
int main() {

    string flips;
    cin >> flips;
    bool horizontal = false;
    bool vertical = false;
    for(char c: flips) {
        if(c == 'H') horizontal = !horizontal;
        else vertical = !vertical;
    }

    if(vertical) {
        if(horizontal) {
            cout << "4 3\n2 1" << endl;
        }
        else {
            cout << "2 1\n4 3" << endl;
        }
    }
    else {
        if(horizontal) {
            cout << "3 4\n1 2" << endl;
        }
        else {
            cout << "1 2\n3 4" << endl;
        }
    }
    
    return 0;
}