#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <unordered_set>

using namespace std;
/*
int findthing(pair <string, string> sr, pair <string, string> lr, pair <string, string> pr, int s, string i, string f)
{
	int j;
	int sp;
	int nl;

	if (i == f)
	{
		if (s == 0)
		{
			cout << "good";
			return 0;
		}
		else
		{
			return 0;
		}
	}

	if (i.find(sr.first) != string::npos)
	{
		sp = i.find(sr.first);
		for (int k = 0; k < (sr.first).size() - 1; k++)
		{
			i.erase(k);
		}
		i.at((sr.first).size() - 1) = sr.second;
		findthing(sr, lr, pr, s - 1, i, f);
	}

}

int main()
{

	// 2019 J5 Rule of Three
	// class code is 624367338

	// use recursion and counting everytime it reccurs until it has done it enough times, then check if it is correct, use for loop
	//checking through each part of the letter combination and go another recursion path if so

	pair <string, string> sr;
	pair <string, string> lr;
	pair <string, string> pr;
	int s;
	string i, f;

	cin >> sr.first >> sr.second;
	cin >> lr.first >> lr.second;
	cin >> pr.first >> pr.second;
	cin >> s >> i >> f;

	findthing(sr, lr, pr, s, i, f);

	cout << "bad";

	return 0;
}*/

typedef pair <string, string> spair;

class findythingy
{
public:
	int rn = 0;
	int pos = 0;
	string sub;
};

spair rs[3];

int tstep;
string fs;

vector <findythingy*> outputr;

unordered_set <string> done;

bool ton(string s, int step)
{
	int t = done.size();
	s += to_string(step);
	done.insert(s);

	if (t == done.size())
	{
		return false;
	}
	return true;
}

int doit(findythingy *ss, int cstep)
{
	int i, p;
	findythingy* pdata;

	if (cstep > tstep)
	{
		return 1;
	}
	if (cstep == tstep)
	{
		if (ss->sub == fs)
		{
			for (i = 0; i < outputr.size(); i++)
			{
				cout << outputr[i]->rn << " " << outputr[i]->pos << " " << outputr[i]->sub << endl;
			}
			cout << ss->rn << " " << ss->pos << " " << ss->sub << endl;

			return 0;
		}
		
		return -1;
	}

	if (ss->rn > 0)
	{
		outputr.push_back(ss);
	}

	for (i = 0; i < 3; i++)
	{
		p = ss->sub.find(rs[i].first);

		while (p != string::npos)
		{
			pdata = new findythingy;
			pdata->rn = i + 1;
			pdata->pos = p + 1;

			pdata->sub = ss->sub;
			pdata->sub.replace(p, rs[i].first.length(), rs[i].second);
			if (ton(pdata->sub, cstep))
			{
				if (doit(pdata, cstep + 1) == 0)
				{
					return 0;
				}
			}
			p = ss->sub.find(rs[i].first, p + rs[i].first.length());
		}
	}

	if (ss->rn > 0)
	{
		outputr.pop_back();
	}

	return -1;

}

int main()
{
	findythingy is;

	cin >> rs[0].first >> rs[0].second;
	cin >> rs[1].first >> rs[1].second;
	cin >> rs[2].first >> rs[2].second;

	cin >> tstep >> is.sub >> fs;

	doit(&is, 0);

	return 0;
}