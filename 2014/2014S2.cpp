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

    int n;
    int i;
    int j;
    string un[31];
    string deux[31];

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> un[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> deux[i];
    }

    if (n == 1)
    {
        cout << "bad";
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = n-1; j > -1; j--)
        {
            if (deux[j] == un[i])
            {
                if (deux[i] != un[j] || deux[i] == deux[j] || un[i] == un[j])
                {
                    cout << "bad";
                    return 0;
                }
            }
        }
    }

    cout << "good";

    return 0;
	
}