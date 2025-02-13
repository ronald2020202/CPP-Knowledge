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

int main()
{
	// 
	// class code is 624367338

	string a;
	string b;
	int noa = 0;//number of asterics
	int nom = 0;
	int i;
	int j;

	cin >> a;
	cin >> b;

	for (i = 0; i < b.size(); i++)
	{
		if (b.at(i) == '*')
		{
			noa++;
		}
	}

	for (i = 0; i < a.size(); i++)
	{
		for (j = 0; j < a.size(); j++)
		{
			if (b.at(j) == a.at(i))
			{
				b.at(j) = '0';
				break;
			}
			if (j == a.size() - 1)
			{
				noa--;
			}
		}
	}

	if (noa < 0)
	{
		cout << 'N';
	}
	else
	{
		cout << 'A';
	}

	return 0;
}