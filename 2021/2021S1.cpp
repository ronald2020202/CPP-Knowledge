#include <iostream>
#include <string>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

int main()
{
	int n;
	int a = 0;
	int o = 0;
	int i;
	int temp;
	cin >> n;

	vector <int> h(n + 1);
	vector <int> w(n);

	for (i = 0; i < n + 1; i++) 
	{
		cin >> h[i];
	}
	for (i = 0; i < n; i++)
	{
		cin >> w[i];
	}

	for (i = 0; i < n; i++)
	{
		temp = (w.at(i) * (h.at(i) + h.at(i + 1))) / 2;
		if ((w.at(i) * (h.at(i) + h.at(i + 1))) % 2 == 1)
		{
			o++;
		}
		a += temp;
	}

	a += o / 2;
	o -= (o / 2) * 2; 

	if (o == 0)
	{
		cout << a << endl;
	}
	else
	{
		cout << a << "." << 5 << endl;
	}

	return 0;
}