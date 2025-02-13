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

		//2014 J4 Question
	int k;
	int m;
	int ii;
	char ck[102];

	cin >> k;
	cin >> m;

	for (int i = 1; i <= k; i++)
	{
		ck[i] = 'y';
	}

	int j = 0;

	for (int l = 0; l < m; l++)
	{
		cin >> ii;

		j = 1;

		for (int i = 1; i < k + 1; i++)
		{
			if (ck[i] == 'y')
			{
				if (j % ii == 0)
				{
					ck[i] = 'n';
				}

				j++;
			}


		}
	}

	for (int i = 1; i < k + 1; i++)
	{
		if (ck[i] == 'y')
		{
			cout << i << endl;
		}
	}

	return 0;
}