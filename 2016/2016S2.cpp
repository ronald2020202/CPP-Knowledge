#include <iostream>
#include <string>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
#include <climits>

using namespace std;

// class code is 624367338

int main()
{
    //

    int q;
    int n;
    vector <int> d;
    vector <int> p;
    int temp;
    int i;
    int counter = 0;

    cin >> q;
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> temp;
        d.push_back(temp);
    }
    for (i = 0; i < n; i++)
    {
        cin >> temp;
        p.push_back(temp);
    }

    sort(d.begin(), d.end());
    sort(p.begin(), p.end());

    if (q == 2) {
        reverse(p.begin(), p.end());
    }

    long sum = 0;
    for (i = 0; i < n; i++) {
        sum += max(d[i], p[i]);
    }

    cout << sum;

    return 0;

    if (q == 1)
    {
        for (i = n-1; i > -1; i--)
        {
            if (d.at(i) > p.at(i))
            {
                counter += d.at(i);
            }
            else
            {
                counter += p.at(i);
            }
        }
    }
    else
    {
        if (n % 2 == 0)
        {
            for (i = n - 1; i > (n/2)-1; i--)
            {
                counter += d.at(i);
                counter += p.at(i);
            }
        }
        else
        {

            for (i = n - 1; i > (n / 2); i--)
            {
                counter += d.at(i);
                counter += p.at(i);
            }

            if (d.at(n / 2) > p.at(n / 2))
            {
                counter += d.at(n / 2);
            }
            else
            {
                counter += p.at(n / 2);
            }
        }
    }

    cout << counter;

    return 0;
}