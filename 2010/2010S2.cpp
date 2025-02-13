#include <iostream>
#include <string>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
#include <climits>
#include <numeric>

using namespace std;

// class code is 624367338



int main()
{
   
	int k;
	char c[21];
	string n[21];
	string s;
	int pos = 0;
	int len = 1;
	string temp;
	string temp1;
	int i;

	cin >> k;

	for (i = 0; i < k; i++)
	{
		cin >> c[i] >> n[i];
	}

	cin >> s;

	i = 0;

	while (pos < s.size())
	{
		if (i == k)
		{
			i = 0;
		}
		if (s.substr(pos, n[i].size()) == n[i])
		{
				pos += n[i].size();
				cout << c[i];
				i = -1;
		}
		i++;
	}

	return 0;
}