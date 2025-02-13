#include <iostream>
#include <string>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
#include <climits>
#include <numeric>

using namespace std;

// class code is 624367338
/*
int shortevent(vector <pair<int, int>> a, int n, int c)
{
    int l;//smallest distance
    for (int i = 0; i < n; i++)
    {
        if (a.at(i).first >= c)
        {
            if (a.at(i).second < l)
            {
                l = a.at(i).second;

            }
        }
    }
}*/

int main()
{
    //check for event that ends first
    //after event, use the end time of the event attended and find shortest event available past that
    //if event starts before end time, doesn't count
    //print out path as collecting data
    /*
    vector <pair<int, int>> a;//events(start time, end time)
    int n;//number of events
    int i;
    int temp1;
    int temp2;
    int c = 0;//current position in time

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> temp1 >> temp2;
        a.push_back({ temp1-1, temp2-1 });
    }

    shortevent(a, n, c);
    */

    int w;
    int n;
    vector <int> ni;
    int temp;
    int i;
    int counter = 3;

    cin >> w;
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> temp;
        ni.push_back(temp);
    }

    if (ni.at(0) > w)
    {
        cout << 0;
        return 0;
    }
    else if (ni.at(0) + ni.at(1) > w)
    {
        cout << 1;
        return 0;
    }
    else if (ni.at(0) + ni.at(1) + ni.at(2) > w)
    {
        cout << 2;
        return 0;
    }
    else if (ni.at(0) + ni.at(1) + ni.at(2) + ni.at(3) > w)
    {
        cout << 3;
        return 0;
    }

    for (i = 0; i < n - 3; i++)
    {
        if ((ni.at(i) + ni.at(i + 1) + ni.at(i + 2) + ni.at(i + 3)) <= w)
        {
            counter++;
        }
        else
        {
            break;
        }
    }

    cout << counter;

    return 0;
}