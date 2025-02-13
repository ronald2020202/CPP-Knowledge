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
   
	int n;
	char s[10001];
	char k[10001];
	int counter = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> k[i];
		if (k[i] == s[i])
		{
			counter++;
		}
	}

	cout << counter;

	return 0;
}