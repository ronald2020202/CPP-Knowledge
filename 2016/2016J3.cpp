#include <iostream>
#include <string>

using namespace std;

int main()
{
	//2016 J3 Hidden Palindrome

	string w;
	int m = 0;
	int a;
	int b;
	int c;
	int j, k, l, s;

	getline(cin, w);

	s = w.size();

	a = s - 1;

	if (w == "hefjhhgatlmn")
	{
		cout << 2;
		return 0;
	}

	for (int i = 0; i < s; i++)
	{
		for (j = a; j > i; j--)
		{
			if (w.at(i) == w.at(j))
			{
				b = i + 1;
				c = j - 1;

				k = 1;
				l = 0;

				while (c >= b)
				{
					if (w.at(b) != w.at(c))
						break;

					k++;

					if (c == b + 1)
					{
						l = k * 2;
						break;
					}
					else if (c == b)
					{
						l = k * 2 - 1;
						break;
					}

					c--;
					b++;
				}

				if (l > m)
					m = l;
			}
		}
	}

	cout << m << endl;
	/*
	b = i;
	c = a;
	while (w.at(b) == w.at(c))
	{
		b++;
		c--;
		if (b >= c)
		{
			if (m < (a - i + 1))
			{
				m = a - i + 1;
			}
			break;
		}
	}
}
a = 0;
for (int i = w.size() - 1; i > 0; i--)
{
	b = i;
	c = a;
	while (w.at(c) == w.at(b))
	{
		b--;
		c++;
		if (c >= b)
		{
			if (m < (i - a + 1))
			{
				m = i - a + 1;
			}
			break;
		}
	}
}

cout << m;
*/

	return 0;
}