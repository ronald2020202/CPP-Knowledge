#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

	int a, b, c, d, t;
	int total;
	int temp;

	cin >> a >> b;
	cin >> c >> d;
	cin >> t;

	temp = t % 2;

	total = abs(a - c) + abs(b - d);

	if (total % 2 == temp && total <= t)
	{
		cout << "Y";
	}
	else
	{
		cout << "N";
	}

	return 0;
}