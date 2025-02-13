#include <iostream>
#include <ios>
#include <limits>
#include <cstring>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int main() {

	string previous;
	int sum;
	string num;

	while (1)
	{
		cin >> num;
		if (num == "99999")
		{
			break;
		}
		sum = num[0] - '0' + num[1] - '0';
		if (sum != 0)
		{
			if (sum % 2 == 0)
			{
				previous = "right ";
			}
			else
			{
				previous = "left ";
			}
		}
		cout << previous << num.substr(2, 3) << endl;
	}

	return 0;
}