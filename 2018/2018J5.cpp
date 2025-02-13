#include <iostream>
#include <ios>
#include <limits>
#include <cstring>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <climits>
#include <cmath>
#include <sstream>

using namespace std;
/*
struct output {
	int rule;
	int pindex;
	string w;

	output(int a, int b, string c) {
		rule = a;
		pindex = b;
		w = c;
	}
};

vector<output> sequence;
vector<string> start;
string i;
string f;
map<string, string> rules;
map<string, int> number;
int s;
size_t found = 0;

bool recursion(int s) {
	if (s == 0) {
		if (i == f) {
			//sequence.push_back(new output());
			return true;
		}
	}

	for (string st : start) {
		found = i.find(st);
		map<size_t, bool> visited;
		
		while (found != string::npos) {

			visited[found] = true;
			string temp = i;
			for (int j = 0; j < st.size(); j++) {
				i[found + j] = rules[st][j];
			}
			if (recursion(s - 1)) {
				output path(number[st], found, i);
				sequence.push_back(path);
				return true;
			}
			i = temp;
			found = i.find(st, found + 1);
			if (visited[found]) {
				break;
			}
		}
	}
}*/

int main() {
	
	//string temp1;
	//string temp2;
	//

	//for (int i = 0; i < 3; i++) {
	//	cin >> temp1 >> temp2;
	//	rules[temp1] = temp2;
	//	start.push_back(temp1);
	//	number[temp1] = i + 1;
	//}
	//
	//cin >> s >> i >> f;

	//bool result = recursion(s);

	//if (result) {
	//	cout << "good";
	//}

	int n;
	int m;
	int temp;
	cin >> n;
	vector<vector<int>> adjin(n + 1, vector<int>());
	vector<vector<int>> adjout(n + 1, vector<int>());
	queue<pair<int, int>> q;
	int minimum = 10001;

	bool reach = true;

	for (int i = 1; i <= n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> temp;
			if (temp != i) {
				adjin[temp].push_back(i);
			}
			adjout[i].push_back(temp);
		}
	}
	vector<int> end;
	for (int i = 2; i <= n; i++) {
		if (adjin[i].size() == 0) {
			reach = false;
		}
		if (adjout[i].size() == 0) {
			q.push({ i, 1 });
			//end.push_back(i);
		}
	}
	//q.push({ 1, 1 });
	int endsize = end.size();
	while (!q.empty()) {
		pair<int, int> front = q.front();
		q.pop();
		if (front.first == 1) {
			minimum = min(minimum, front.second);
		}
		/*for (int i : end) {
			if (i == front.first) {
				minimum = min(minimum, front.second);
			}
		}*/
		else if(front.second < minimum){
			for (int next : adjin[front.first]) {
				q.push({ next, front.second + 1 });
			}
		}
	}
	if (reach) {
		cout << "Y" << endl;
	}
	else {
		cout << "N" << endl;
	}

	cout << minimum << endl;

	return 0;
}