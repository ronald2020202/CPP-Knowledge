#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

	int i, j, m, n, p;
	char c;
	int x;
	bool* mm, * nn;
	int mt = 0, nt = 0;

	cin >> m >> n >> p;

	mm = new bool[m];
	nn = new bool[n];

	fill(mm, mm + m, false);
	fill(nn, nn + n, false);

	for (i = 0; i < p; i++)
	{
		cin >> c >> x;

		x--;

		if (c == 'R')
		{
			mm[x] = !mm[x];
		}
		else
		{
			nn[x] = !nn[x];
		}
	}

	for (i = 0; i < m; i++)
	{
		if (mm[i])
		{
			mt++;
		}
	}

	for (i = 0; i < n; i++)
	{
		if (nn[i])
		{
			nt++;
		}
	}

	x = mt * n + nt * m - mt * nt * 2;

	cout << x << endl;

	return 0;
}