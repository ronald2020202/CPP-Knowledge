#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) { return 0; }
    if (n <= 3) { return 1; }

    int x = sqrt(n);

    for (int i = 2; i <= x; i++) {
        if (n % i == 0) { return 0; }
    }
    return 1;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        if (isPrime(n)) {
            cout << n << " " << n << endl;
            continue;
        }
        int low = n-1;
        int high = n+1;
        
        while (low > 0) {
            if (isPrime(low) && isPrime(high)) {
                cout << low << " " << high << endl;
                break;
            }
            low--;
            high++;
        }
    }

    return 0;
}