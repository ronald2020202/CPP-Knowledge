#include <iostream>
#include <string> 
#include <algorithm>

using namespace std;


int main()
{
	// 2018 J4 Sunflowers
	// class code is 624367338

	int n;
	int i, j, k;
	int a[102][102];
	int temp[102][102];
	int c = 0;
	int nt = 0;
	int p;

	cin >> n; //Input

	for (i = 0; i < n; i++) //This loop is for the input of the array
	{
		for (j = 0; j < n; j++)
		{
			cin >> a[i][j];
			temp[i][j] = a[i][j];
		}
	}
	
	p = n - 1;
	
	if (a[0][0] > a[p][0] && a[0][0] > a[0][p] && a[0][0] > a[p][p])//If the top-left corner is the biggest, and then what nt will be
	{
		nt = 2;
	}
	if (a[p][0] > a[0][0] && a[p][0] > a[0][p] && a[p][0] > a[p][p])//If the top-right corner is the biggest, and then what nt will be
	{
		nt = 3; //If this fails make it 3

	}
	if (a[0][p] > a[p][0] && a[0][p] > a[0][0] && a[0][p] > a[p][p])//If the bottom-left corner is the biggest, and then what nt will be
	{
		nt = 1; //If this fails make it 1
	}
	if (a[p][p] > a[p][0] && a[p][p] > a[0][p] && a[p][p] > a[0][0])//If the bottom-left corner is the biggest, and then what nt will be
	{
		nt = 0;
	}
	


	for (k = 0; k < nt; k++) //This repeats the spinning of the array for a number of times, specifically nt times, based off the orientation of the array
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				a[j][i] = temp[abs(i - (n - 1))][j];
			}
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				temp[i][j] = a[i][j];
			}
		}
	}


	for (i = 0; i < n; i++)//This for loop is the output
	{
		for (j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}