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

using namespace std;

vector<vector<char>> grid;
int counter = 0;
int wordsize;
int r;
int c;

pair<int, int> nextLetter(int direction, int i, int j) {//consider when index in corners
	if (direction == 1 && j != c - 1) {
		return { i,j + 1 };
	}
	else if (direction == -1 && j != 0) {
		return { i,j - 1 };
	}
	else if (direction == 2 && i != 0) {
		return { i - 1,j };
	}
	else if (direction == -2 && i != r - 1) {
		return { i + 1,j };
	}
	else if (direction == 3 && i != 0 && j != c - 1) {
		return { i - 1,j + 1 };
	}
	else if (direction == -3 && i != r - 1 && j != 0) {
		return {i + 1,j - 1};
	}
	else if (direction == 4 && i != r - 1 && j != c - 1) {
		return { i + 1,j + 1 };
	}
	else if (direction == -4 && i != 0 && j != 0) {
		return { i - 1, j - 1 };
	}
	return { -1, -1 };
}

void canFind(int direction, int starti, int startj, string word, int wordi, bool turned) {
	if (wordi == wordsize) {//if reached end of word, add to total number of words found and return
		counter++;
		return;
	}
	pair<int, int> letter;
	if (direction == 0) {
		letter = nextLetter(1, starti, startj);
		if (letter.first != -1 && grid[letter.first][letter.second] == word[wordi]) {
			canFind(1, letter.first, letter.second, word, wordi + 1, false);
		}
		letter = nextLetter(-1, starti, startj);
		if (letter.first != -1 && grid[letter.first][letter.second] == word[wordi]) {
			canFind(-1, letter.first, letter.second, word, wordi + 1, false);
		}
		letter = nextLetter(2, starti, startj);
		if (letter.first != -1 && grid[letter.first][letter.second] == word[wordi]) {
			canFind(2, letter.first, letter.second, word, wordi + 1, false);
		}
		letter = nextLetter(-2, starti, startj);
		if (letter.first != -1 && grid[letter.first][letter.second] == word[wordi]) {
			canFind(-2, letter.first, letter.second, word, wordi + 1, false);
		}
		letter = nextLetter(3, starti, startj);
		if (letter.first != -1 && grid[letter.first][letter.second] == word[wordi]) {
			canFind(3, letter.first, letter.second, word, wordi + 1, false);
		}
		letter = nextLetter(-3, starti, startj);
		if (letter.first != -1 && grid[letter.first][letter.second] == word[wordi]) {
			canFind(-3, letter.first, letter.second, word, wordi + 1, false);
		}
		letter = nextLetter(4, starti, startj);
		if (letter.first != -1 && grid[letter.first][letter.second] == word[wordi]) {
			canFind(4, letter.first, letter.second, word, wordi + 1, false);
		}
		letter = nextLetter(-4, starti, startj);
		if (letter.first != -1 && grid[letter.first][letter.second] == word[wordi]) {
			canFind(-4, letter.first, letter.second, word, wordi + 1, false);
		}
	}
	else {//this is when there is one direction
		if (!turned) {//if one direction and can turn
			if (direction == 1 || direction == -1) {//change from horizontal to vertical
				letter = nextLetter(2, starti, startj);
				if (letter.first != -1 && grid[letter.first][letter.second] == word[wordi]) {
					canFind(2, letter.first, letter.second, word, wordi + 1, true);
				}
				letter = nextLetter(-2, starti, startj);
				if (letter.first != -1 && grid[letter.first][letter.second] == word[wordi]) {
					canFind(-2, letter.first, letter.second, word, wordi + 1, true);
				}
			}
			else if (direction == 2 || direction == -2) {//change from vertical to horizontal
				letter = nextLetter(1, starti, startj);
				if (letter.first != -1 && grid[letter.first][letter.second] == word[wordi]) {
					canFind(1, letter.first, letter.second, word, wordi + 1, true);
				}
				letter = nextLetter(-1, starti, startj);
				if (letter.first != -1 && grid[letter.first][letter.second] == word[wordi]) {
					canFind(-1, letter.first, letter.second, word, wordi + 1, true);
				}
			}
			else if (direction == 3 || direction == -3) {//change from bl to tr to tl to br
				letter = nextLetter(4, starti, startj);
				if (letter.first != -1 && grid[letter.first][letter.second] == word[wordi]) {
					canFind(4, letter.first, letter.second, word, wordi + 1, true);
				}
				letter = nextLetter(-4, starti, startj);
				if (letter.first != -1 && grid[letter.first][letter.second] == word[wordi]) {
					canFind(-4, letter.first, letter.second, word, wordi + 1, true);
				}
			}
			else if (direction == 4 || direction == -4) {//change from tl to br to bl to tr
				letter = nextLetter(3, starti, startj);
				if (letter.first != -1 && grid[letter.first][letter.second] == word[wordi]) {
					canFind(3, letter.first, letter.second, word, wordi + 1, true);
				}
				letter = nextLetter(-3, starti, startj);
				if (letter.first != -1 && grid[letter.first][letter.second] == word[wordi]) {
					canFind(-3, letter.first, letter.second, word, wordi + 1, true);
				}
			}
		}
		//if the next letter in the direction is not word[wordi], return, else run func
		letter = nextLetter(direction, starti, startj);
		if (letter.first != -1 && grid[letter.first][letter.second] == word[wordi]) {
			canFind(direction, letter.first, letter.second, word, wordi + 1, turned);
		}
		else {
			return;
		}
	}
	return;
}

int main() {

	string word;
	cin >> word;
	wordsize = word.size();
	cin >> r;
	cin >> c;
	char temp;

	for (int i = 0; i < r; i++) {
		cin >> temp;
		grid.push_back({ temp });
		for (int j = 1; j < c; j++) {
			cin >> temp;
			grid[i].push_back(temp);
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (grid[i][j] == word[0]) {
				canFind(0, i, j, word, 1, false);
			}
		}
	}
	cout << counter;

	return 0;
}
