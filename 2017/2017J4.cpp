#include <iostream>
#include <string> 
#include <algorithm>

using namespace std;


int main()
{
// 2017 J4 Favourite Times
	// class code is 624367338

	int d; // Number of minutes to obserb
	int o = 0; // Counter
	int i;
	int h1 = 1; // Hours first digit
	int h2 = 2; // Hours second digit
	int m1 = 0; // Minutes first digit
	int m2 = 0; // Minutes second digit
	int c = 0;
	int temp;
	int temp1 = 0;

	cin >> d; // Input

	for (i = 0; i < d + 1; i++)
	{
		if (m2 == 10) // THis if statement makes sure the minutes don't go to 110 but instead 20
		{
			m2 = 0;
			m1++;
		}
		if (m1 == 6) // This if statement makes sure the clock doesn't go to 60 minutes
		{
			m1 = 0;
			h2++;
		}
		if (h2 == 10) // This if statement makes sure the hours don't go to 010 but instead 10
		{
			h2 = 0;
			h1 = 1;
		}
		if (h1 == 1 && h2 == 3) // This if statement makes sure the hour doesn't go to 13 hours
		{
			h1 = 0;
			h2 = 1;
		}

		if (h1 == 0) // This is if it is like 01:23
		{
			if (h2 - m1 == m1 - m2)
			{
				o++;
			}
		}
		if (h1 == 1) // This is if it is like 11:23
		{
			if (h1 - h2 == h2 - m1 && h2 - m1 == m1 - m2)
			{
				o++;
			}
		}
		m2++; // This adds one minute. 
		c++;
		if (c == 720)
		{
			temp = d / 720;
			o *= temp;
			temp1 = d % 720;
		}
		if (c == (720 + temp1 + 1))
		{
			break;
		}
	}

	cout << o; // This is the output

	return 0;
}