#include <iostream>
#include <string> 
#include <algorithm>
#include <cstdio>

using namespace std;


int main()
{
	// 2016 J4 Arrival Time
	// class code is 624367338

	int n;
	int as = 100;
	int ds = 100;
	int a;
	int d;
	int i;

	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> a >> d;

		if (a > d)
		{
			ds -= a;
		}
		else if (d > a)
		{
			as -= d;
		}
	}

	cout << as << endl << ds;

	return 0;
}