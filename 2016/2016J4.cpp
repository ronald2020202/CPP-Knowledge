#include <iostream>

using namespace std;

int main() {
	
	string temp;
	int h1;
	int h2;
	int m1;
	int m2;

	int hour;
	int minute;

	cin >> temp;

	h1 = temp[0] - '0';
	h2 = temp[1] - '0';
	m1 = temp[3] - '0';
	m2 = temp[4] - '0';

	hour = 10 * h1 + h2;
	minute = 10 * m1 + m2;

 	for (int i = 0; i < 120; i++) {
		if (hour >= 7 && hour <= 9 || hour >= 15 && hour <= 18) {//|| hour == 10 && minute == 0 || hour == 19 && minute == 0
			minute ++;
		}
		minute ++;
		if (minute >= 60) {
			minute -= 60;
			hour++;
			if (hour >= 24) {
				hour = 0;
			}
		}
	}
	if (hour < 10) {
		cout << "0";
	}
	cout << hour << ":";
	if (minute < 10) {
		cout << "0";
	}
	cout << minute;

	return 0;
}