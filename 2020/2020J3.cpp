#include <iostream>
#include <string>

using namespace std;

int main()
{
	// 2020 J3 Art

	int n;
	int l1 = 101;
	int l2 = 101;
	int r1 = -1;
	int r2 = -1;
	int x;
	int y;
	char c;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> c >> y;

		if (l1 > x)
		{
			l1 = x;
		}
		if (l2 > y)
		{
			l2 = y;
		}
		if (r1 < x)
		{
			r1 = x;
		}
		if (r2 < y)
		{
			r2 = y;
		}
	}
	cout << l1 - 1 << c << l2 - 1 << endl << r1 + 1 << c << r2 + 1;

	return 0;
}