#include <iostream>

using namespace std;

int main()
{
	
	// 2011 J2 Who Has Seen The Wind
	// class code is 624367338

	int t[10000];
	int i;

	cin >> t[0];
	cin >> t[1];

	for (i = 2; i < 10002; i++)
	{
		t[i] = (t[i - 2] - t[i - 1]);
		if (t[i] > t[i - 1])
		{
			
			cout << i + 1;
			break;
		}
	}

	return 0;
}