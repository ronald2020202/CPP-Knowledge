#include <iostream>
#include <string>

using namespace std;

char vowel(char c)
{
	string vo = "aeiou";
	int i;
	int k;
	int s = 100;
	int p;

	for (i = 0; i < 5; i++)
	{
		k = abs(c - vo.at(i));
		if (k < s)
		{
			s = k;
			p = i;
		}
	}
	return vo.at(p);
}

int main()
{
	//2015 J3 R?varspr?ket

	string w;
	string we;
	string letters = "aeiou";

	getline(cin, w);

	for (int i = 0; i < w.size(); i++)
	{
		we += w.at(i);
		if (letters.find(w.at(i)) != string::npos)
		{
			continue;
		}
		else
		{
			we += vowel(w.at(i));

			if (w.at(i) + 1 > 'z')
			{
				we += 'z';
			}
			else
			{
				if (letters.find(w.at(i) + 1) != string::npos)
					we += (w.at(i) + 2);
				else
					we += (w.at(i) + 1);
			}
		}
	}
	cout << we;

	return 0;
}