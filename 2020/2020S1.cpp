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
	vector<pair<int, int>> tx;
	int n;
	int o = -1;//ones digit
	int t = -1;//twos digit
	int i;
	int temp;
	int temp1;
	int temp2;
	int time;
	int distance;

	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> temp >> temp1;
		tx.push_back({ temp, temp1 });
	}

	sort(tx.begin(), tx.end());

	for (i = 0; i < n - 1; i++)
	{
		time = tx.at(i + 1).first - tx.at(i).first;
		distance = tx.at(i + 1).second - tx.at(i).second;
		temp = abs(distance / time);
		temp1 = abs(distance % time);
		temp2 = abs((temp1 * 10) / time);
		if (temp > o)
		{
			o = temp;
			t = temp2;
		}
		else if (temp == o)
		{
			if (temp2 > t)
			{
				t = temp2;
			}
		}
		//need to convert remainder(temp1) into decimal, so can compare if temp is equal to 
		//the highest number to print out later
	}

	cout << o << "." << t;

	return 0;
}