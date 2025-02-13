#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	// 2016 J4 Arrival Time
// class code is 624367338

	int t, c;
	int a[100];
	int i;
	int te = 0;
	int tc = 0;
	string s;

	cin >> t;
	cin >> c;

	for (i = 0; i < c; i++)
	{
		cin >> a[i];
	}

	sort(a, a + c);

	while (te < t)
	{
		te += a[tc];
		tc++;
	}
	if (te > t)
	{
		tc--;
	}

	cout << tc;

	return 0;
}