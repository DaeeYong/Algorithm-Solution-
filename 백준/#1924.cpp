#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

int Month[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31 };
const char* Week[7] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };

int main()
{
	int month, day;
	cin >> month >> day;

	for (int i = 0; i < month; i++) {
		day += Month[i];
	}
	cout << Week[day % 7] << '\n';

	return 0;
}