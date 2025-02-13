#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>
#include <queue>

using namespace std;

bool done = false;

int nextstep(vector<vector<int> > &r, int m, int n, int stepx, int stepy)
{
	int i, j;

	if (done) {
		return 0;
	}

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			
			if ((i+1) * (j+1) == r[stepx][stepy])
			{
				if (i == m - 1 && j == n - 1)
				{
					done = true;
					return 0;
				}
				else
				{
					nextstep(r, m, n, i, j);
				}
			}
		}
	}
	return 0;
}

int main()
{
	int m, n, i, j, stepx = 0, stepy = 0;

	cin >> m;
	cin >> n;

	vector<vector<int> > r(1001, vector<int>(1001));

	map<int, vector<pair<int, int> > > vals;
	map<pair<int, int>, bool> visited;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cin >> r[i][j];
			vals[r[i][j]].push_back({ i, j });
		}
	}

	int target = r[1][1];

	queue<pair<int, int> > q;
	if (m * n == target) {
		done = true;
	}
	q.push({ m, n });
	while (!q.empty() && !done) {
		pair<int, int> cur = q.front();
		visited[cur] = true;

		int num = cur.first * cur.second;

		for (const auto& pos : vals[num]) {
			int check = pos.first * pos.second;
			if (check == target) {
				done = true;
				break;
			}
			if (!visited[pos]) {
				q.push(pos);
			}
		}

		q.pop();
	}

	if (done)
	{
		cout << "yes";
	}
	else
	{
		cout << "no";
	}

	return 0;
}