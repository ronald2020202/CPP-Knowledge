#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
/*
int main()
{
	// 2020 J3 Art
	// class code is 624367338

	int n;
	int x;
	int y;
	int lx = 100;
	int ly = 100;
	int rx = 0;
	int ry = 0;
	int i;

	cin >> n;

	for (i = 0; i < n; i++)
	{
		scanf("%d,%d", &x, &y);

		if (x < lx)
		{
			lx = x;
		}
		else if (x > rx)
		{
			rx = x;
		}
		if (y < ly)
		{
			ly = y;
		}
		else if (y > ry)
		{
			ry = y;
		}
	}
	
	cout << lx - 1 << ", " << ly - 1 << endl << rx + 1 << ", " << ry + 1;

    return 0;
}

int main()
{
	// 2020 J4 Cyclic Shifts
	// class code is 624367338

	string t;
	string s;
	string temp;
	int i;

	cin >> t >> s;

	for (i = 0; i < s.size(); i++)
	{
		temp = s.substr(i) + s.substr(0, i);

		if (t.find(temp) != string::npos)
		{
			cout << "yes";
			return 0;
		}
	}
	
	cout << "no";

	return 0;
}*/
/*
bool ton;

int nextstep(int r[1000][1000], int m, int n, int stepx, int stepy)
{
	int i, j;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i * j == r[stepx][stepy])
			{
				if (i == m - 1 && j == n - 1)
				{
					ton = true;
					return 0;
				}
				else
				{
					nextstep(r, m, n, i, j);
				}
			}
		}
	}
}

int main()
{
	int m, n, i, j;
	int r[1000][1000];

	cin >> m;
	cin >> n;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> r[i][j];
		}
	}

	nextstep(r, m, n, 0, 0);

	if (ton == true)
	{
		cout << "yes";
	}
	else
	{
		cout << "no";
	}

	return 0;
}*/

int main()
{
	// 2019 J4 Cyclic Flipper

	int oo = 1, ol = 2;
	int lo = 3, ll = 4;
	int temp;
	int i;
	int a;
	string f;

	getline(cin, f);

	a = f.size();

	for (i = 0; i < a; i++)
	{
		if (f.at(i) == 'H')
		{
			temp = lo;
			lo = oo;
			oo = temp;

			temp = ll;
			ll = ol;
			ol = temp;
		}
		else if (f.at(i) == 'V')
		{
			temp = ol;
			ol = oo;
			oo = temp;

			temp = ll;
			ll = lo;
			lo = temp;
		}
	}

	cout << oo << " " << ol << endl;
	cout << lo << " " << ll;

	return 0;
}