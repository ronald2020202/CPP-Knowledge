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

    int j;
    int a;
    vector <int> b;
    vector <pair<int, int>> c;
    string temp;
    int temp1;
    int i;
    int counter = 0;

    cin >> j;
    cin >> a;

    for (i = 0; i < j; i++)
    {
        cin >> temp;
        if (temp == "S")
        {
            b.push_back(0);
        }
        if (temp == "M")
        {
            b.push_back(1);
        }
        if (temp == "L")
        {
            b.push_back(2);
        }
    }
    for (i = 0; i < a; i++)
    {
        cin >> temp >> temp1;
        if (temp == "S")
        {
            c.push_back({ temp1 - 1, 0 });
        }
        if (temp == "M")
        {
            c.push_back({temp1 - 1, 1});
        }
        if (temp == "L")
        {
            c.push_back({temp1 - 1, 2});
        }
    }

    sort(c.begin(), c.end());

    for (i = 0; i < a; i++)
    {
        if (b.at(c.at(i).first) == -1)
        {
            continue;
        }
        else
        {
            if (b.at(c.at(i).first) >= c.at(i).second)
            {
                counter++;
                b.at(c.at(i).first) = -1;
            }
        }
    }

    cout << counter;

    return 0;
}