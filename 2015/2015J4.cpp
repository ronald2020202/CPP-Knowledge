#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

typedef pair<int, int> ipair;

int main()
{
	// 2015 J4 Wait Time
	// class code is 624367338

	int m;
	int i;
	int t = 0;
	char a;
	int b;
	ipair data[101];

	for (i = 1; i < 101; i++)
	{
		data[i].second = 0;
	}
	cin >> m;

	for (i = 0; i < m; i++)
	{
		cin >> a >> b;

		if (a == 'W')
		{
			t += b - 2;
		}
		else if (a == 'R')
		{
			data[b].first = t;
		}
		else if (a == 'S')
		{
			data[b].second += t - data[b].first;
			data[b].first = 0;
		}
		t++;
	}

	for (i = 1; i < 101; i++)
	{
		if (data[i].second != 0)
		{
			if (data[i].first == 0)
			{
				cout << i << " " << data[i].second << endl;
			}
			else
			{
				cout << i << " -1" << endl;
			}
		}
		else if (data[i].first != 0)
		{
			cout << i << " -1" << endl;
		}
	}

	return 0;
}