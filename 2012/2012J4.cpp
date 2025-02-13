#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	// 2016 J4 Arrival Time
// class code is 624367338

	int k;
	string w;
	string l = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int t;
	int i, j;

	cin >> k;
	cin >> w;

	for (i = 0; i < w.size(); i++)
	{
		for (j = 0; j < 26; j++)
		{
			if (w.at(i) == l.at(j))
			{
				t = j;
				break;
			}
		}

		t -= 3 * (i + 1) + k;

		if (t < -24)
		{
			for (j = 0; j < -t / 26 + 1; j++)
			{
				if (t < 0)
				{
					t = 26 - abs(t);
				}
			}
		}
		if (t < 0)
		{
			t = 26 - abs(t);
		}

		w.at(i) = l.at(t);

	}

	cout << w;
	return 0;
}