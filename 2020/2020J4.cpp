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
	string a;
	int lx = 50;
	int ly = 50;
	int rx = 50;
	int ry = 50;
	int i;

	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> x >> a >> y;

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
}*/

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
}